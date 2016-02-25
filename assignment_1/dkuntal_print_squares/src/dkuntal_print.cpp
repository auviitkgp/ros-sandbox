#include "ros/ros.h"
#include "std_msgs/Int64.h"

void chatSubs1(const std_msgs::Int64::ConstPtr& msg){
	ROS_INFO("Numbers - %d",msg->data);
}
void chatSubs2(const std_msgs::Int64::ConstPtr& msg){
	ROS_INFO("Squares - %d",msg->data);
}
int main(int argc,char **argv){
	ros::init(argc, argv, "print");
	ros::NodeHandle n;
	ros::Rate loop_rate(1);
	ros::Subscriber sub1=n.subscribe("numbers",1000,chatSubs1);
//Subscribes to the topic named "numbers"
	loop_rate.sleep();
	ros::Subscriber sub2=n.subscribe("squares",1000,chatSubs2);
//Subscribes to the topic named "squares"
	
	ros::spin();

	return 0;
}
