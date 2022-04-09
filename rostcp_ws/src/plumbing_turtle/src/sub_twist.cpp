/*
 * @Author: Yoring
 * @Date: 2022-04-04 22:43:40
 * @LastEditors: Yoring
 * @LastEditTime: 2022-04-04 23:25:44
 * @FilePath: /rostcp_ws/src/plumbing_turtle/src/sub_twist.cpp
 * @Description: 订阅乌龟运动的位姿信息
 * 
 * Copyright (c) 2022 by Yoring, All Rights Reserved 2050. 
 */

#include<ros/ros.h>
#include<turtlesim/Pose.h>



void DoPose(const turtlesim::PoseConstPtr& pose)
{
    ROS_INFO("坐标： %.2f %.2f 朝向：%.2f", pose->x, pose->y, pose->theta);
}


int main(int argc, char * argv[])
{
    // 打印中文
    setlocale(LC_ALL, "");

    // 初始化节点
    ros::init(argc, argv, "turtle_sub1");

    // 节点句柄
    ros::NodeHandle hd;

    // 创建
    ros::Subscriber sub = hd.subscribe<turtlesim::Pose>("turtle1/pose", 10, DoPose);

    // 回头
    ros::spin();
}

