/*
 * @Author: Yoring
 * @Date: 2022-04-04 18:16:45
 * @LastEditors: Yoring
 * @LastEditTime: 2022-04-04 23:08:38
 * @FilePath: /rostcp_ws/src/plumbing_turtle/src/pub_twist.cpp
 * @Description: 给乌龟发topic demo
 * 
 * Copyright (c) 2022 by Yoring, All Rights Reserved 2050. 
 */

#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
/*
    编写 ROS 节点，控制小乌龟画圆

    准备工作:
        1.获取topic(已知: /turtle1/cmd_vel)
        2.获取消息类型(已知: geometry_msgs/Twist)
        3.运行前，注意先启动 turtlesim_node 节点

        查看话题信息的时候用 rostopic info /turtle1/cmd_vel后面跟的是话题名称，里面有Type
        查看具体的消息定义的时候用 rosmsg info geometry_msgs/Twist 这里就是Type

    实现流程:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建发布者对象
        4.循环发布运动控制消息
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    ros::init(argc, argv, "manual_twist");

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 100);

    geometry_msgs::Twist twist;

    twist.linear.x = 1;
    twist.linear.y = 0;
    twist.linear.z = 0;

    twist.angular.x = 0;
    twist.angular.y = 0;
    twist.angular.z = 1;

    ros::Rate rate(10);
    while (ros::ok())
    {
        pub.publish(twist);
        ROS_INFO("控制量为线速度x: %f, 角速度z: %f", twist.linear.x, twist.angular.z);
        rate.sleep();
    }
    ros::spinOnce();
}