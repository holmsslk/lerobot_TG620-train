import base64
import json
import os
import sys
import threading
import time

# Prefer distro-provided numpy/cv2 pair to avoid ABI mismatch with user-site numpy.
_DIST_PACKAGES = "/usr/lib/python3/dist-packages"
if os.path.isdir(_DIST_PACKAGES):
    if _DIST_PACKAGES in sys.path:
        sys.path.remove(_DIST_PACKAGES)
    sys.path.insert(0, _DIST_PACKAGES)

import cv2
import rclpy
import zmq
from cv_bridge import CvBridge, CvBridgeError
from rcl_interfaces.msg import ParameterDescriptor
from rclpy.node import Node
from sensor_msgs.msg import Image


class TGCameraZmqBridge(Node):
    def __init__(self):
        super().__init__("tg_camera_zmq_bridge")

        dyn = ParameterDescriptor(dynamic_typing=True)
        self.declare_parameter("image_topic", "/camera/color/image_raw", dyn)
        self.declare_parameter("camera_name", "front", dyn)
        self.declare_parameter("port", 5555, dyn)
        self.declare_parameter("fps", 30.0, dyn)
        self.declare_parameter("jpeg_quality", 80, dyn)

        self._image_topic = str(self.get_parameter("image_topic").value)
        self._camera_name = str(self.get_parameter("camera_name").value)
        self._port = int(self.get_parameter("port").value)
        self._fps = float(self.get_parameter("fps").value)
        self._jpeg_quality = int(self.get_parameter("jpeg_quality").value)

        self._bridge = CvBridge()
        self._lock = threading.Lock()
        self._latest_encoded: str | None = None
        self._latest_timestamp = 0.0

        self._subscription = self.create_subscription(Image, self._image_topic, self._on_image, 10)

        self._zmq_context = zmq.Context()
        self._socket = self._zmq_context.socket(zmq.PUB)
        self._socket.setsockopt(zmq.SNDHWM, 20)
        self._socket.setsockopt(zmq.LINGER, 0)
        self._socket.bind(f"tcp://*:{self._port}")

        period_s = 1.0 / max(self._fps, 1.0)
        self._timer = self.create_timer(period_s, self._on_publish_timer)

        self.get_logger().info(
            f"TG camera bridge started. topic={self._image_topic}, name={self._camera_name}, "
            f"port={self._port}, fps={self._fps:.1f}"
        )

    def _on_image(self, msg: Image) -> None:
        try:
            frame = self._bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
        except CvBridgeError as exc:
            self.get_logger().warning(f"Failed to convert ROS image: {exc}")
            return

        ok, buffer = cv2.imencode(".jpg", frame, [int(cv2.IMWRITE_JPEG_QUALITY), self._jpeg_quality])
        if not ok:
            self.get_logger().warning("cv2.imencode failed, dropping frame")
            return

        timestamp = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9
        if timestamp <= 0:
            timestamp = time.time()

        encoded = base64.b64encode(buffer).decode("utf-8")
        with self._lock:
            self._latest_encoded = encoded
            self._latest_timestamp = float(timestamp)

    def _on_publish_timer(self) -> None:
        with self._lock:
            if self._latest_encoded is None:
                return

            payload = {
                "timestamps": {self._camera_name: self._latest_timestamp},
                "images": {self._camera_name: self._latest_encoded},
            }

        try:
            self._socket.send_string(json.dumps(payload), flags=zmq.NOBLOCK)
        except zmq.Again:
            pass

    def destroy_node(self) -> bool:
        self._timer.cancel()

        if getattr(self, "_socket", None) is not None:
            self._socket.close()
        if getattr(self, "_zmq_context", None) is not None:
            self._zmq_context.term()

        return super().destroy_node()


def main(args=None) -> None:
    rclpy.init(args=args)
    node = TGCameraZmqBridge()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
