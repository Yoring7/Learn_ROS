#include<ros/ros.h>
#include<tcp_pub_sub/person.h>


void DoPerson(const tcp_pub_sub::person::ConstPtr &person)
{
    ROS_INFO("收到的消息为：%s %d %.2f", person->name.c_str(), 
                        person->age, person->height);
}

int main(int argc, char *argv[])
{
    // 中文乱码
    setlocale(LC_ALL, "");

    // 初始化节点
    ros::init(argc, argv, "person_sub");

    // 节点句柄
    ros::NodeHandle hd;

    // 创建订阅者对象
    ros::Subscriber sub = hd.subscribe<tcp_pub_sub::person>("liaotian", 10, DoPerson);

    // spin()函数回头 等待callback
    ros::spin();
}