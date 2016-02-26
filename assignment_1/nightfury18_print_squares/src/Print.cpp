#include "ros/ros.h"
#include "std_msgs/Int64.h"

void numbercallback(const std_msgs::Int64::ConstPtr& msg)
{
	ROS_INFO("Number : %d\n", msg->data);
}

void squarecallback(const std_msgs::Int64::ConstPtr& msg)
{
	ROS_INFO("Square : %ld\n", msg->data);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "Print");
	ros::NodeHandle n;
	ros::Rate loop_rate(1);

	ros::Subscriber s1 = n.subscribe("topic_number", 1000, numbercallback);
	loop_rate.sleep();
	ros::Subscriber s2 = n.subscribe("topic_square", 1000, squarecallback);

	ros::spin();

	return 0;
}