/*
 * @Author: Yoring
 * @Date: 2022-04-04 13:47:07
 * @LastEditors: Yoring
 * @LastEditTime: 2022-04-04 14:20:16
 * @FilePath: /rostcp_ws/src/plumbing_server_client/src/client01.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by Yoring WS, All Rights Reserved 2050. 
 */

#include<ros/ros.h>
#include<plumbing_server_client/addint.h>


int main(int argc, char *argv[])
{
    // 中文乱码问题
    setlocale(LC_ALL, "");
    // ROS_INFO("第一个参数是：%s", argv[0]);

    // 检查输入参数，3个是当前程序路径 加两个参数
    if (argc != 3)
    {
        ROS_INFO("参数错误！");
        return 0;
    }
    // 初始化节点
    ros::init(argc, argv, "client01");
    // 节点句柄
    ros::NodeHandle hd;

    // 创建客户端对象
    ros::ServiceClient client = hd.serviceClient<plumbing_server_client::addint>("addint");

    // 组织请求
    plumbing_server_client::addint ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);

    // 等到服务器启动
    // 函数1
    client.waitForExistence();

    // 函数2
    // ros::service::waitForService("addint");
    
    // 提交请求
    if (client.call(ai))
    {
        ROS_INFO("响应成功, sum = %d", ai.response.sum);
    }
    else
        ROS_INFO("响应失败！");

}