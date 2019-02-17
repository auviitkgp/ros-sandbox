#include "ros/ros.h"
#include "std_msgs/Int64.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "Number");
	ros::NodeHandle n;

	ros::Publisher pub1 = n.advertise<std_msgs::Int64>("topic_number", 1000);

	ros::Rate loop_rate(1);
	int count = 1;

	while(ros::ok())
	{
		std_msgs::Int64 msg;
		msg.data = count;
		pub1.publish(msg);

		ros::spinOnce();
		loop_rate.sleep();

		++count;
	}

	return 0;
}
