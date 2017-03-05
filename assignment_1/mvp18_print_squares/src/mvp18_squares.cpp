#include "ros/ros.h"
#include "std_msgs/Int64.h"


void topic_numbers_Callback(const std_msgs::Int64::ConstPtr& msg)
{
	int n;
	ros::NodeHandle sq1;
	ros::Publisher square_pub = sq1.advertise<std_msgs::Int64>("topic_squares", 1000);

	n = msg->data;
  std_msgs::Int64 square;
	square.data = n*n;
	square_pub.publish(square);
	ros::spin();
}


int main(int argc, char **argv)
{
	ros::init(argc, argv, "mvp18_squares");

	ros::NodeHandle sq2;
	ros::Subscriber sub = sq2.subscribe("topic_numbers", 1000, topic_numbers_Callback);


	ros::spin();

	return 0;
}
