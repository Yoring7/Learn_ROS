/*
 * @Author: Yoring
 * @Date: 2022-04-04 11:23:12
 * @LastEditors: Yoring
 * @LastEditTime: 2022-04-04 14:25:18
 * @FilePath: /rostcp_ws/src/plumbing_server_client/src/server.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by hopechart, All Rights Reserved 2050. 
 */
#include<ros/ros.h>
#include<plumbing_server_client/addint.h>

bool DoNum(plumbing_server_client::addint::Request &request,
        plumbing_server_client::addint::Response &response)
{
    // 处理请求
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("我接受到的是：%d %d", num1, num2);

    // 响应
    response.sum = num1 + num2;
    ROS_INFO("我处理后的结果是：%d", response.sum);

    return true;
}

int main(int argc, char *argv[])
{
    // 中文乱码
    setlocale(LC_ALL, "");

    // 初始化节点
    ros::init(argc, argv, "server01");

    // 节点句柄
    ros::NodeHandle hd;

    // 创建服务端对象
    ros::ServiceServer server = hd.advertiseService("addint", DoNum);

    ROS_INFO("服务端已启用...");
    ros::spin();

    return 0;
}