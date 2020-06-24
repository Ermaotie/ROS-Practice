#include<ros/ros.h>
#include<topic_learning/fbnq.h>

void Callback(const topic_learning::fbnq::ConstPtr&msg)
{
    ROS_INFO("Index: %d, Value: %d ",msg->index,msg->value);
}
int main(int argc, char**argv)
{
    ros::init(argc, argv,"topic_subscriber");
    ros::NodeHandle n;
    ros::Subscriber fbnq_info_sub=n.subscribe("/fbnq_info", 10,Callback);
    ros::spin();
    return 0;
}
