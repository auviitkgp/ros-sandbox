#include "ros/ros.h"
#include "std_msgs/Int64.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "numbers_ghostwriternr");											// Initialize
	ros::NodeHandle n;																		// Handle created for the node
	ros::Publisher topic_numbers_pub = n.advertise<std_msgs::Int64>("topic_numbers", 1000);	// Tell the master that we are going to be publishing a message of type std_msgs/Int64 on the topic topic_numbers.
	ros::Rate loop_rate(1);     															// Frequency set to 1 Hz
	for(int i = 0;ros::ok();i++)
	{
		std_msgs::Int64 m;
		m.data = i;
		topic_numbers_pub.publish(m);
		ROS_INFO("%ld", m.data);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}