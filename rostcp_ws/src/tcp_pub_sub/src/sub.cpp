#include"ros/ros.h"
#include"std_msgs/String.h"
#include<string>

void DoMsg(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("收到的消息为：%s", msg->data.c_str());
}

int main(int argc, char *argv[])
{
    // 中文乱码
    setlocale(LC_ALL, "");

    // 初始化节点
    ros::init(argc, argv, "sub");

    // 节点句柄
    ros::NodeHandle hd;

    // 创建订阅者对象
    ros::Subscriber sub = hd.subscribe("fangzi", 10, DoMsg);
    

    // spin()函数回头 等待callback
    ros::spin();
}