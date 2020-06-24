#include<ros/ros.h>
#include<actionlib/server/simple_action_server.h>
#include<action_learning/demoAction.h>

class demoAction
{
    protected:
        ros::NodeHandle n;
        actionlib::SimpleActionServer<action_learning::demoAction> action_server ;
        std::string action_name;

        action_learning::demoResult res;
        action_learning::demoFeedback fb; 

    public:
        demoAction(std::string name):
        action_server(n,name,boost::bind(&demoAction::executeCB,this,_1),false),
        action_name(name)
        {
            action_server.start();
        }
        ~demoAction(void)
        {   
        }
        void executeCB(const action_learning::demoGoalConstPtr &goal)
        {
            ros::Rate r(1); //loop_rate=1 Hz
            bool success=true;

            fb.sequence.clear();
            fb.sequence.push_back(0);
            fb.sequence.push_back(1);

            ROS_INFO("demoAction is inited!");
            // start to calculate

            for(int i=1;i<=goal->order;i++)
            {
                if(action_server.isPreemptRequested()|| !ros::ok())
                {
                    ROS_INFO("%s : Preempted", action_name.c_str());
                    action_server.setPreempted();
                    success = false;
                    break;
                }
                fb.sequence.push_back(fb.sequence[i]+fb.sequence[i-1]);
                action_server.publishFeedback(fb);
                ROS_INFO("FEEDBACK!!");
                r.sleep();
            }

            if(success)
            {
                res.sequence = fb.sequence;
                // ROS_INFO("%s : Succeeded!",action_name.c_str());
                action_server.setSucceeded(res);
                ROS_INFO("%d", res.sequence[19]);
            }
        }
};


int main(int argc, char**argv)
{
    ros::init(argc,argv,"action_server");
    demoAction demo("demo_action");
    ros::spin();
    return 0;
}