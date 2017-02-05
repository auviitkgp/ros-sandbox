#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include "std_msgs/UInt64.h"

#include <sstream>

//The callback function for listening from topic_numbers
void numCallback(const std_msgs::Int64::ConstPtr& msg)
{
	ROS_INFO("Number : %d\nListened from \"topic_numbers\"",msg->data);
}

//The callback function for listening from topic_sqaures
void sqrCallback(const std_msgs::UInt64::ConstPtr& msg)
{
	ROS_INFO("Square of the Number : %d\nListened from \"topic_squares\"",msg->data);
}


int main(int argc, char **argv)
{
	//Iniliatize the node
	ros::init(argc,argv,"Printer");
	
	//Create a node handler object
	ros::NodeHandle n;
	
	//Add subsciption to topic_numbers
	ros::Subscriber sub_num = n.subscribe("topic_numbers", 1000, numCallback);
	
	//Add subscription to topic_squares
	ros::Subscriber sub_sqr = n.subscribe("topic_squares", 1000, sqrCallback);
	
	ros::spin();
	
	return 0;
}
