#include "ros/ros.h"
#include "std_msgs/Int64.h"

#include <sstream>


int main(int argc, char **argv)
{
	//Initilaize the node
	ros::init(argc,argv,"Number_Publisher");
	
	//Create a nodehandler object
	ros::NodeHandle n;
	
	
	//Create a publisher object to publish to topic_numbers with buffer capacity 1000
	ros::Publisher num_pub = n.advertise<std_msgs::Int64>("topic_numbers",1000);
	
	//Set the publishing rate as 1 Hz
	ros::Rate loop_rate(1);
	
	//Initialize the number to 1 to start publishing from
	int num = 1;
	
	//Continue publishing until the node is in valid state
	while(ros::ok())
	{
		
		//Create a msg object to publish
		std_msgs::Int64 msg;
		
		msg.data = num;
		
		//Publish the message to the topic_numbers using the created publisher object
		num_pub.publish(msg);
		
		ros::spinOnce();
		
		
		//Sleep until the next publishing is required determined by the publishing rate
		loop_rate.sleep();
		
		
		//Increment the number to publish next
		++num;
	}
	return 0;
}


