#include "ros/ros.h"
#include "std_msgs/Int64.h"

void chatterCallback1(const std_msgs::Int64::ConstPtr& msg)
{
	ROS_INFO("topic_numbers: %ld", msg->data);
}

void chatterCallback2(const std_msgs::Int64::ConstPtr& msg)
{
	ROS_INFO("topic_squares: %ld", msg->data);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "print_ghostwriternr");     									// Initialize ROS
	ros::NodeHandle n;																	// Handle created for the node
	ros::Subscriber sub1 = n.subscribe("topic_numbers", 1000, chatterCallback1);		// Subscribed to the topic_numbers topic with the master.
	ros::Subscriber sub2 = n.subscribe("topic_squares", 1000, chatterCallback2);		// Subscribed to the topic_numbers topic with the master.
	ros::spin();
	return 0;
}