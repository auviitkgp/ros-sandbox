#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <sstream>
#include <ros/callback_queue.h>

using namespace std;

int m;

void chatterCallback_num(const std_msgs::Int32::ConstPtr msg)
{
 ROS_INFO("square: [%d]", msg->data);
 m=msg->data;
}	

int main(int argc, char **argv)
{
 ros::init(argc, argv, "talker2");
 ros::NodeHandle n;
 ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("topic_squares", 1000);
 ros::Rate loop_rate(1);
 //int count = 0;

 while (ros::ok()) 
 {
 	 ros::Subscriber sub1 = n.subscribe("topic_numbers", 1000,chatterCallback_num);
 	 ros::getGlobalCallbackQueue()->callAvailable(ros::WallDuration(3.0));
 	
	 std_msgs::Int32 msg;
	 std::stringstream ss;
	 msg.data = m*m;
	 ROS_INFO("sending %d", msg.data);
	 chatter_pub.publish(msg);
	 ros::spinOnce();
	 loop_rate.sleep();
	 //++count;
 }

 return 0;
}


