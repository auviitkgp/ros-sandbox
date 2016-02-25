#include "ros/ros.h"
#include "std_msgs/Int64.h"

std_msgs::Int64 msg_;;
ros::Publisher chat_pub;

void chatSubs(const std_msgs::Int64::ConstPtr& msg){
	msg_.data=msg->data*msg->data;
	if(ros::ok()){
		chat_pub.publish(msg_);
		ROS_INFO("Pub2 : %d",msg_.data);
	}
}
int main(int argc,char **argv){
	ros::init(argc,argv,"squares");
	ros::NodeHandle n;

	ros::Subscriber sub=n.subscribe("numbers", 1000, chatSubs);
//Subscribes to the topic named "numbers"
	chat_pub=n.advertise<std_msgs::Int64>("squares",1000);
//Publishes to the topic named "squares"
	ros::Rate loop_rate(1);
	ros::spin();
	
	return 0;
}
