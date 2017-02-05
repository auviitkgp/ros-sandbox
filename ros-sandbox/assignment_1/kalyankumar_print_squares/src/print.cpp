#include "ros/ros.h"	//includes headers necessary to use most common elements of ROS
#include "std_msgs/Int64.h"	//includes std_msgs/Int64 message

void chatterCallback1(const std_msgs::Int64::ConstPtr& msg)
{
	ROS_INFO("topic_numbers - %ld\n", msg->data);	//equivalent to cout
}

void chatterCallback2(const std_msgs::Int64::ConstPtr& msg)
{
	ROS_INFO("topic_squares - %ld\n", msg->data);	//equivalent to cout
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "print");     //Initializes ROS
	ros::NodeHandle n;	//This creates a handle for this process' node
	ros::Subscriber sub1 = n.subscribe("topic_numbers", 1000, chatterCallback1);	//Subscribes to the topic "topic_numbers" and calls callback function as a new message arrives
	ros::Subscriber sub2 = n.subscribe("topic_squares", 1000, chatterCallback2);	//Subscribes to the topic "topic_squares" and calls callback function as a new message arrives
	ros::spin();
	return 0;
}
