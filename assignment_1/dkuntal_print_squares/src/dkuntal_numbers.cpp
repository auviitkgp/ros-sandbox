#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include <sstream>

int main(int argc, char **argv){
	ros::init(argc, argv, "numbers");
	ros::NodeHandle n;

	ros::Publisher chat_pub=n.advertise<std_msgs::Int64>("numbers",1000);
//Publishes data to the topic named "numbers"
	ros::Rate loop_rate(1);

	int count=1;
	while(ros::ok()){
		std_msgs::Int64 msg;
		msg.data=count++;
		
		ROS_INFO("Pub1 : %d",msg.data);
		chat_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
