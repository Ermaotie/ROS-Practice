#include<ros/ros.h>
#include<actionlib/client/simple_action_client.h>
#include<actionlib/client/terminal_state.h>
#include<action_learning/demoAction.h>

int main(int argc,char**argv)
{
    ros::init(argc,argv,"demo_client");
    // 创建 action_client
    actionlib::SimpleActionClient<action_learning::demoAction> action_client("demo_action", true);    //true --> Don't need ros::spin()
    //  等待 server端
    ROS_INFO("waiting for acessing server");
    action_client.waitForServer();
    // 创建 请求文件
    action_learning::demoGoal goal;
    ROS_INFO("action file is ready!");

    goal.order = 20;

    action_client.sendGoal(goal);
    ROS_INFO("SENT!");

    bool finished_before_timeout = action_client.waitForResult(ros::Duration(30,0));
    if (finished_before_timeout)
    {
        ROS_INFO("success");
    }
    else
    {
        ROS_INFO("failed");
    }
    return 0;
}