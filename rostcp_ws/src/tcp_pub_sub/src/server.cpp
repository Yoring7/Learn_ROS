/*
 * @Author: Yoring
 * @Date: 2022-04-03 22:35:22
 * @LastEditors: Yoring
 * @LastEditTime: 2022-04-05 00:42:42
 * @FilePath: /rostcp_ws/src/tcp_pub_sub/src/server.cpp
 * @Description: 发布者demo
 * 
 * Copyright (c) 2022 by Yoring WS, All Rights Reserved 2050. 
 */
#include"ros/ros.h"
#include"std_msgs/String.h"
#include<sstream>
#include<tcp_pub_sub/person.h>


int main(int argc, char *argv[])
{
    // 测试可以用 rostopic echo liaotian
    // 打印中文
    setlocale(LC_ALL, "");

    // 初始化节点
    ros::init(argc, argv, "server");

    // 节点句柄
    ros::NodeHandle hd;

    // 创建发布者对象
    ros::Publisher pub_obj = hd.advertise<std_msgs::String>("fangzi", 10);

    // 需要发布的消息
    std_msgs::String msg;

    // 发布频率
    ros::Rate rate(10);
    unsigned int count = 0;

    // 先休眠，让订阅者可以订阅到
    ros::Duration(3).sleep();

    // 写循环发布消息
    while (ros::ok())
    {
        count++;
        
        // 字符串拼接
        std::stringstream ss;
        ss << "hello " << count;

        // c++字符串转成ros的字符串类型
        msg.data = ss.str();

        // 发布
        pub_obj.publish(msg);
        // 需要转成c字符串类型
        ROS_INFO("发布的消息是: %s", ss.str().c_str());
        rate.sleep();
    }
    
}