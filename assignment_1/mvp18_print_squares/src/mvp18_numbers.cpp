#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include <sstream>

int main(int argc, char **argv){
	ros::init(argc, argv, "mvp18_numbers");
	ros::NodeHandle n;

	ros::Publisher numbers_pub=n.advertise<std_msgs::Int64>("topic_numbers",1000);
//Publishes data to the topic named "numbers"
	ros::Rate loop_rate(1);

	int count=1;
	while(ros::ok()){
		std_msgs::Int64 num;
		num.data=count++;

		ROS_INFO("Pub1 : %d",num.data);
		numbers_pub.publish(num);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
