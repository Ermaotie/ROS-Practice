#include<ros/ros.h>
#include<topic_learning/fbnq.h>
void numsInit(int[], int);
int main(int argc, char **argv)
{
    ros::init(argc, argv,"topic_publisher");
    ros::NodeHandle n;
    ros::Publisher fbnq_info_pub = n.advertise<topic_learning::fbnq>("/fbnq_info", 10);
    ros::Rate loop_rate(1);
    int count = 0;
    int cou = 0;
    int nums[15];
    numsInit(nums,15);
    while (ros::ok()&&cou<15)
    {
        topic_learning::fbnq _fbnq;
        _fbnq.value = nums[cou];
        _fbnq.index = cou++;
        fbnq_info_pub.publish(_fbnq);
        ROS_INFO("Value has been past");
        loop_rate.sleep();
    }
    return 0;
}
void numsInit(int nums[], int index)
{
    for(int i=0;i<index;i++)
    {
        if(i==0||(i==1))
        {
            nums[i] = 1;
        }
        else nums[i] =nums[i-1] + nums[i-2];
    }
}
