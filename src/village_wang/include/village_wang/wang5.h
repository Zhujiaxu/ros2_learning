#ifndef _WANG5_HPP_
#define _WANG5_HPP_
#include <rclcpp/rclcpp.hpp>
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int32.hpp"
using std::placeholders::_1;
class Wang5 : public rclcpp::Node
{
public:
    /*
    Wang5():Node("wang5")
    {
        RCLCPP_INFO(this->get_logger(), "Hello, this is %s node!", this->get_name());
    }
        */
    Wang5(std::string name_);
    private:
    rclcpp::Publisher<std_msgs::msg::UInt32>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    void topic_callback(const std_msgs::msg::String::SharedPtr msg);


};
#endif // _WANG5_HPP_