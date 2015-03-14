#include "ros/ros.h"
#include "std_msgs/Int64.h"

void chatterCallback(const std_msgs::Int64::ConstPtr &msg)
{
	int i;
	ros::NodeHandle p;
	ros::Publisher square_pub = p.advertise<std_msgs::Int64>("topic_squares", 1000);
	i = msg->data;
	std_msgs::Int64 msg1;
	msg1.data = i*i;
	square_pub.publish(msg1);
	ros::spinOnce();
}
	

int main(int argc, char **argv)
{
	ros::init(argc, argv, "squares");	//Initializes ROS
	ros::NodeHandle s;	//This creates a handle for this process' node
	ros::Subscriber sub = s.subscribe("topic_numbers", 1000, chatterCallback);	//Subscribes to the topic "topic_numbers" and calls callback function as a new message arrives
	ros::spin();
	return 0;
}
