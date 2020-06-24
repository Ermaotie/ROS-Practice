#include<ros/ros.h>
#include<srv_learning/demo.h>
#include<cstdlib>

int main(int argc, char**argv)
{
    ros::init(argc,argv,"demo_client");
    if(argc!=3)
    {
        ROS_INFO("cmd:rosrun srv_learning srv_client arg0 arg1");
        return 1;
    }
    ros::NodeHandle n;
    ros::ServiceClient ros_client = n.serviceClient<srv_learning::demo>("ros_demo_srv");
    //声明srv,接受参数
    srv_learning::demo srv ;
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);

    if (ros_client.call(srv))
    {
        ROS_INFO("Access successfully!");
    }
    else
    {
        ROS_INFO("Access defeatedly!");
        return 1;
    }
    return 0;
}