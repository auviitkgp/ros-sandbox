#include "ros/ros.h"
#include "std_msgs/Int64.h"

void chatterCallback(const std_msgs::Int64::ConstPtr &msg)
{
	long int i;
	ros::NodeHandle n;
	ros::Publisher topic_squares_pub = n.advertise<std_msgs::Int64>("topic_squares", 1000);
	i = msg->data * msg->data;
	std_msgs::Int64 msg1;
	msg1.data = i;
	topic_squares_pub.publish(msg1);
	ROS_INFO("%ld", msg1.data);
	ros::spin();
}
	

int main(int argc, char **argv)
{
	ros::init(argc, argv, "squares_ghostwriternr");								// Initialize ROS
	ros::NodeHandle n;															// Handle created for the node
	ros::Subscriber sub = n.subscribe("topic_numbers", 1000, chatterCallback);	// Subscribed to the topic_numbers topic with the master. 
	ros::spin();																// ros::spin() enters a loop, calling message callbacks as fast as possible. 
	return 0;
}