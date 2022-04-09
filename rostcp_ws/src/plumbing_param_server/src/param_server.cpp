/*
 * @Author: Yoring
 * @Date: 2022-04-04 15:08:38
 * @LastEditors: Yoring
 * @LastEditTime: 2022-04-04 15:50:08
 * @FilePath: /rostcp_ws/src/plumbing_param_server/src/param_server.cpp
 * @Description: 参数服务器demo
 * 
 * Copyright (c) 2022 by Yoring WS, All Rights Reserved 2050. 
 */
#include<ros/ros.h>

int main(int argc, char *argv[])
{   

    // 查看可以用rosparam list/get
    
    // 初始化节点
    ros::init(argc, argv, "set_param");

    // NodeHandle~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // 第一种方法以节点句柄的方式更改
    ros::NodeHandle nh;
    nh.setParam("type", "name");
    nh.setParam("radius", 0.15);

    // ros::~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ros::param::set("type_", "name");
    ros::param::set("radius_", 0.12);

    // 改~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ros::param::set("radius_", 12);

    // 删~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // 查~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    return 0;
}
