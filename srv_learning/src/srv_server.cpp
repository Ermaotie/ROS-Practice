#include<ros/ros.h>
#include<srv_learning/demo.h>

bool calculation(srv_learning::demo::Request &req, srv_learning::demo::Response &res)
{
    res.result = req.a + req.b;
    ROS_INFO("res = %ld",(long int) res.result);
    return true;
}
int main(int argc, char**argv)
{
    ros::init(argc,argv,"demo_server");
    ros::NodeHandle n;
    ros::ServiceServer demo_server = n.advertiseService("ros_demo_srv",calculation);
    ROS_INFO("Server is ready!");
    ros::spin();
    return 0;
}