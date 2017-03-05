#include "ros/ros.h"		
#include "std_msgs/Int32.h"
using namespace ros;
void topic_numbers_Callback(const std_msgs::Int32::ConstPtr& msg)
{
	int n;
	NodeHandle sq1;   			
	Publisher square_pub = sq1.advertise<std_msgs::Int32>("topic_squares", 1000);  
									
	n = msg->data;        			
	std_msgs::Int32 square;			
	square.data = n*n;				
	square_pub.publish(square);		
	spin();					
}
	

int main(int argc, char **argv)
{
	init(argc, argv, "rakeshbal99_squares");	
									
	NodeHandle sq2;			
	Subscriber sub = sq2.subscribe("topic_numbers", 1000, topic_numbers_Callback);
	spin();
				
	return 0;
}