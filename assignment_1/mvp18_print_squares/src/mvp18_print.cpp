#include "ros/ros.h"
#include "std_msgs/Int64.h"

void callback_topic_numbers(const std_msgs::Int64::ConstPtr& num){
	ROS_INFO("topic_numbers - %d",num->data);
}
void callback_topic_squares(const std_msgs::Int64::ConstPtr& square){
	ROS_INFO("topic_squares - %d",square->data);
}
int main(int argc,char **argv){
	ros::init(argc, argv, "mvp18_print");
	ros::NodeHandle n;
	ros::Rate loop_rate(1);
	ros::Subscriber sub1=n.subscribe("topic_numbers",1000,callback_topic_numbers);
//Subscribes to the topic named "numbers"
	loop_rate.sleep();
	ros::Subscriber sub2=n.subscribe("topic_squares",1000,callback_topic_squares);
//Subscribes to the topic named "squares"

	ros::spin();

	return 0;
}
