/*
 * @Author: Yoring
 * @Date: 2022-04-05 01:22:49
 * @LastEditors: Yoring
 * @LastEditTime: 2022-04-05 01:30:07
 * @FilePath: /rostcp_ws/src/plumbing_turtle/src/set_turtle_color.cpp
 * @Description: 参数服务器设置乌龟背景
 * 
 * Copyright (c) 2022 by Yoring, All Rights Reserved 2050. 
 */
#include<ros/ros.h>

int main(int argc, char *argv[])
{
    // 节点初始化
    ros::init(argc, argv, "set_turtle_color");

    // 节点句柄
    ros::NodeHandle nh("turtlesim");

    nh.setParam("background_r",0);
    nh.setParam("background_g",255);
    nh.setParam("background_b",123);

    // ros::param::set("/turtlesim/background_r",0);
    // ros::param::set("/turtlesim/background_g",0);
    // ros::param::set("/turtlesim/background_b",0);


    return 0;
}
