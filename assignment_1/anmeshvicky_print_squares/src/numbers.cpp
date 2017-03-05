#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "numbers");
	ros::NodeHandle n;  
	ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("/topic_numbers", 1);
	ros::Rate loop_rate(1); 
	int count=1;
	while (ros::ok())

	{
		std_msgs::Int32 msg;
		msg.data = count;
		chatter_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		count++;
	}
	return 0;
}
