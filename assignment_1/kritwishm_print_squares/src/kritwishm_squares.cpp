#include "ros/ros.h"
#include "std_msgs/Int64.h"
std_msgs::Int64 msg1;
ros::Publisher chatter_pub;
void chatterCallback(const std_msgs::Int64::ConstPtr& msg)
{
  
	msg1.data=msg->data*msg->data;
	if (ros::ok())
  	{
  		chatter_pub.publish(msg1);
  		ROS_INFO("Published Number: %d", (msg1.data));
	}
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "squares");

  	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("topic_numbers", 1000, chatterCallback);
  	chatter_pub=n.advertise<std_msgs::Int64>("topic_squares",1000);
  	ros::Rate loop_rate(1);
	
	ros::spin();

  return 0;
}
