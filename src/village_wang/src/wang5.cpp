#include "wang5.h"
//jk,
Wang5::Wang5(std::string name_): Node(name_)
{
    RCLCPP_INFO(this->get_logger(), "Hello, this is %s node!", this->get_name());
    publisher_ = this->create_publisher<std_msgs::msg::UInt32>("make_money", 10);
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "sex_girl", 10, std::bind(&Wang5::topic_callback, this, _1));
}

void Wang5::topic_callback(const std_msgs::msg::String::SharedPtr msg)
{
   RCLCPP_INFO(this->get_logger(), "I received: '%s'", msg->data.c_str()); 
   std_msgs::msg::UInt32 money;
    money.data = 10;
    publisher_->publish(money);
    
}
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Wang5>("wang5");
   // RCLCPP_INFO(node->get_logger(), "Hello, this is %s node!", node->get_name());
    //spin必须指针
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}