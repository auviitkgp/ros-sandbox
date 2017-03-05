#include "ros/ros.h"
#include "std_msgs/Int32.h"

void chatterCallback1(const std_msgs::Int32::ConstPtr& msg)
{
	ROS_INFO("topic_numbers  %d ", msg->data);
}
void chatterCallback2(const std_msgs::Int32::ConstPtr& msg)
{
	ROS_INFO("topic_squares  %d ", msg->data);
}

int main(int argc, char **argv)
{

	ros::init(argc, argv, "print");

	ros::NodeHandle n;
	ros::Rate loop_rate(1);

	ros::Subscriber sub1 = n.subscribe("topic_numbers", 1000, chatterCallback1);
	loop_rate.sleep();
	ros::Subscriber sub2 = n.subscribe("topic_squares", 1000, chatterCallback2);

	  
	ros::spin();

	return 0;
}
