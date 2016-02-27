#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <boost/function.hpp>
#include <boost/function_equal.hpp>
#include <ros/callback_queue.h>


class callers
{
  public:
  void subscribes();
  void chatterCallback_sq(const std_msgs::Int32::ConstPtr);
  void chatterCallback_num(const std_msgs::Int32::ConstPtr);
};

void callers::chatterCallback_sq(const std_msgs::Int32::ConstPtr msg) 
{
 ROS_INFO("squares: [%d] ", msg->data);
}

void callers::chatterCallback_num(const std_msgs::Int32::ConstPtr msg)
{
 ROS_INFO("number: [%d]", msg->data);
}	
void callers::subscribes()
{
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("topic_numbers", 1000, &callers::chatterCallback_num, this);
	ros::Subscriber sub1 = n.subscribe("topic_squares", 1000,&callers::chatterCallback_sq,this);
	ros::spin();		
}

int main(int argc, char **argv) 
{
 ros::init(argc, argv, "listener");
 
 callers call;
 call.subscribes(); 
 return 0;
}

