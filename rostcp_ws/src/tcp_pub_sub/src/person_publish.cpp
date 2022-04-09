/*
 * @Author: Yoring
 * @Date: 2022-04-04 01:44:54
 * @LastEditors: Yoring
 * @LastEditTime: 2022-04-04 15:48:08
 * @FilePath: /rostcp_ws/src/tcp_pub_sub/src/person_publish.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by Yoring WS, All Rights Reserved 2050. 
 */
#include<ros/ros.h>
#include<string>
#include"tcp_pub_sub/person.h"

int main(int argc, char *argv[])
{

    // 测试用 rosservice call addint "num1: 7 num2: 3"
    // 中文乱码问题
    setlocale(LC_ALL, "");

    // 节点初始化
    ros::init(argc, argv, "person_publish");

    // 节点句柄
    ros::NodeHandle hd;

    // 创建发布者对象
    ros::Publisher pub = hd.advertise<tcp_pub_sub::person>("liaotian", 10);

    // 被发布的数据
    tcp_pub_sub::person person;
    person.name = "张三";
    person.height = 1.73;
    person.age = 1;

    // 发布频率
    ros::Rate rate(2);

    // 循环发布
    while (ros::ok())
    {
        // 发布
        pub.publish(person);

        // 每次年龄加1
        person.age += 1;

        // 休眠
        rate.sleep();

        ros::spinOnce();
    }
    
}