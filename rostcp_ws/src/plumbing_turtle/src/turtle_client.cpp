/*
 * @Author: Yoring
 * @Date: 2022-04-05 00:22:44
 * @LastEditors: Yoring
 * @LastEditTime: 2022-04-05 00:41:25
 * @FilePath: /rostcp_ws/src/plumbing_turtle/src/turtle_client.cpp
 * @Description: 向乌龟/spawn服务发送请求创建新的乌龟
 * 
 * Copyright (c) 2022 by Yoring, All Rights Reserved 2050. 
 */
#include<ros/ros.h>
#include"turtlesim/Spawn.h"

int main(int argc, char *argv[])
{
    // 中文乱码问题
    setlocale(LC_ALL, "");

    // 初始化节点
    ros::init(argc, argv, "turtle_client");
    // 节点句柄
    ros::NodeHandle hd;
    // 创建客户端对象
    ros::ServiceClient client = hd.serviceClient<turtlesim::Spawn>("/spawn");

    // 组织请求
    turtlesim::Spawn turtle;
    turtle.request.x = 2;
    turtle.request.y = 4;
    turtle.request.theta = 0;
    turtle.request.name = "turtle_son2";

    // 等待
    client.waitForExistence();

    // 提交请求
    // 提交请求
    if (client.call(turtle))
    {
        ROS_INFO("响应成功, 新乌龟叫：%s", turtle.response.name.c_str());
    }
    else
        ROS_INFO("响应失败！");
        
    return 0;
}