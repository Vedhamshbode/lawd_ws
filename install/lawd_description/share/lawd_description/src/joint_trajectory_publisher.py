from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
import rclpy
from rclpy.node import Node

class JointTrajectoryPublisher(Node):
    def __init__(self):
        super().__init__('joint_trajectory_publisher')
        self.publisher = self.create_publisher(JointTrajectory, '/joint_trajectory_controller/joint_trajectory', 10)
        timer_period = 2.0  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        traj_msg = JointTrajectory()
        traj_msg.joint_names = ['ext_frontleftfirst', 'ext_backleftfirst', 'ext_frontrightfirst', 'ext_backrightfirst', 'first_frontleftsec', 'first_backleftsec', 'first_frontrightsec', 'first_backrightsec']

        point = JointTrajectoryPoint()
        point.positions = [1.0]  # target position
        point.time_from_start.sec = 2  # 2 seconds to reach the target

        traj_msg.points.append(point)
        self.publisher.publish(traj_msg)

def main(args=None):
    rclpy.init(args=args)
    joint_trajectory_publisher = JointTrajectoryPublisher()
    rclpy.spin(joint_trajectory_publisher)
    joint_trajectory_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
