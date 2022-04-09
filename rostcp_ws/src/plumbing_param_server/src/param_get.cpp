/*
 * @Author: Yoring
 * @Date: 2022-04-04 15:53:24
 * @LastEditors: Yoring
 * @LastEditTime: 2022-04-04 16:31:30
 * @FilePath: /rostcp_ws/src/plumbing_param_server/src/param_get.cpp
 * @Description: 获取参数服务器的参数demo
 * 
 * Copyright (c) 2022 by Yoring WS, All Rights Reserved 2050. 
 */
/*
    参数服务器操作之查询_C++实现:
    在 roscpp 中提供了两套 API 实现参数操作
    ros::NodeHandle

        param(键,默认值) 
            存在，返回对应结果，否则返回默认值

        getParam(键,存储结果的变量)
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamCached键,存储结果的变量)--提高变量获取效率
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamNames(std::vector<std::string>)
            获取所有的键,并存储在参数 vector 中 

        hasParam(键)
            是否包含某个键，存在返回 true，否则返回 false

        searchParam(参数1，参数2)
            搜索键，参数1是被搜索的键，参数2存储搜索结果的变量

    ros::param ----- 与 NodeHandle 类似

*/
#include<ros/ros.h>
#include<vector>

int main(int argc, char *argv[])
{   
    setlocale(LC_ALL, "");
    // 查看可以用rosparam list/get
    
    // 初始化节点
    ros::init(argc, argv, "get_param");

    ros::NodeHandle nh;

    // 两个参数，第一个为键值，第二个为默认值
    // 1、param
    float radius = nh.param("radius", 3.0);
    ROS_INFO("radius: %f", radius);

    // 2、getParam
    if (nh.getParam("radius_", radius))
        ROS_INFO("radius: %f", radius);
    else
        ROS_INFO("键值不存在！");

    // getParamNames(std::vector<std::string>)
    std::vector<std::string> names;
    nh.getParamNames(names);
    for (auto &&name : names)
    {
        ROS_INFO("遍历到的元素为： %s",name.c_str());
    }
    

    return 0;
}
