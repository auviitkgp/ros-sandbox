#include "ros/ros.h"
#include "std_msgs/Int64.h"

ros::Publisher squarePub;

void squarecallback(const std_msgs::Int64::ConstPtr &msg)
{
	std_msgs::Int64 smsg;
	smsg.data = msg->data * msg->data;

	ROS_INFO("From Square, Number : %ld :: Square : %ld\n", msg->data, smsg.data);
	squarePub.publish(smsg);

}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "Square");
	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("topic_number", 1000, squarecallback);
	squarePub = n.advertise<std_msgs::Int64>("topic_square", 1000);

	ros::Rate loop_rate(1);
	loop_rate.sleep();
	ros::spin();

	return 0;
}