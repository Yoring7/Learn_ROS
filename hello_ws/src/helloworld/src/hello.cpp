#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "hello");

    ros::NodeHandle n;

    ROS_INFO("Hello world! 哈哈哈哈");
    return 0;
}