#include "ros/ros.h"	//includes headers necessary to use most common elements of ROS
#include "std_msgs/Int64.h"	//includes std_msgs/Int64 message

int main(int argc, char **argv)
{
	ros::init(argc, argv, "numbers");	//Initializes ROS
	ros::NodeHandle n;	//This creates a handle for this process' node
	ros::Publisher chatter_pub = n.advertise<std_msgs::Int64>("topic_numbers", 1000);	//Tells the master that we are going to publish onto the topic "topic_numbers"
	ros::Rate loop_rate(1);     //This sets the frequency at which we publish
	for(int y1 = 0;ros::ok();y1++)
	{
		std_msgs::Int64 x1;
		x1.data = y1;
		chatter_pub.publish(x1);	//This publishes x1 onto the topic
		ros::spinOnce();
		loop_rate.sleep();	//put to sleep for the remaining time
	}
	return 0;
}
