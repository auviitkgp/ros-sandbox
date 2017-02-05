#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include "std_msgs/UInt64.h"

#include <sstream>

std_msgs::UInt64 smsg;   //The message to publish,ie,the sqaure of the number read

ros::Publisher sqr_pub;  //The publisher object to publish to topic_sqaures


//The callback function to read from topic_numbers
void numberCallback(const std_msgs::Int64::ConstPtr& msg)
{
	if(ros::ok())
	{
		smsg.data = (msg->data)*(msg->data);  //Calculate the square of the number read
		sqr_pub.publish(smsg);  //Publish the square to  the topic_sqaures
	}
}
		
		
	

int main(int argc, char **argv)
{
	//Initialize the node
	ros::init(argc,argv,"Square_Publisher");
	
	//Create a nodehandler object
	ros::NodeHandle n;
	
	//Create a publisher object to publish to the topic_sqaures with buffer capacity 1000
	sqr_pub = n.advertise<std_msgs::UInt64>("topic_squares",1000);
	
	//Suscribe to the topic_numbers and get a subsciber object
	ros::Subscriber sub = n.subscribe("topic_numbers", 1000, numberCallback);
	
	
	ros::spin();
	
	
	return 0;
}
