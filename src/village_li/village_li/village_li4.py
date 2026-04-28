import rclpy
from std_msgs.msg import String
from std_msgs.msg import UInt32
from rclpy.node import Node
class writenode(Node):
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info("大家好，我是作家%s." % name)
        self.pub_novel_ = self.create_publisher(String, "sex_girl",10)
        self.sub_novel_ = self.create_subscription(UInt32, "make_money", self.make_money_callback, 10)

        self.i=0
        self.timer = self.create_timer(1.0, self.timer_callback)
        self.acount=80

    def timer_callback(self):
        msg = String()
        msg.data = "这是第%d章小说的内容。" % self.i
        self.pub_novel_.publish(msg)
        self.get_logger().info("发布了第%d章小说的内容。" % self.i)
        self.i += 1
        
    def make_money_callback(self, msg):
        '''try:
            amount = int(msg.data)
        except Exception:
            amount = 0
        '''
        self.acount += msg.data
        self.get_logger().info("我又赚了一笔钱！当前余额: %d" % self.acount)

def main(args=None):
    """
    ros2运行该节点的入口函数
    编写ROS2节点的一般步骤
    1. 导入库文件
    2. 初始化客户端库
    3. 新建节点对象
    4. spin循环节点
    5. 关闭客户端库
    """
    rclpy.init(args=args) # 初始化rclpy
    node = writenode("li4")  # 新建一个节点
    rclpy.spin(node) # 保持节点运行，检测是否收到退出指令（Ctrl+C）
    rclpy.shutdown() # 关闭rclpy
