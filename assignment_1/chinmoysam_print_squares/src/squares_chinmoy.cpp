#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include <sstream>

std_msgs::Int64 sq_msg;

ros::Publisher chatter_pub;

void chatternumberCallback(const std_msgs::Int64::ConstPtr& msg)
	{
  		
		if(ros::ok())
			{

				sq_msg.data = msg->data * msg->data;

				ROS_INFO("SQUARE = %d", sq_msg.data);

				chatter_pub.publish(sq_msg);

			}

  		
	}	

int main(int argc, char **argv)
{
	
	ros::init(argc, argv, "square");

	ros::NodeHandle n;

	ros::Subscriber subnumber = n.subscribe("topic_numbers",1000,chatternumberCallback);

	chatter_pub = n.advertise<std_msgs::Int64>("topic_squares", 1000);

	ros::spin();

	return 0;

}