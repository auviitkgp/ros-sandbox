#include "ros/ros.h"			
#include "std_msgs/Int32.h"
#include <sstream>
using namespace ros;

int main(int argc, char **argv)
{
  
  init(argc, argv, "rakeshbal99_numbers"); 
  NodeHandle n; 		
  Publisher numbers_pub = n.advertise<std_msgs::Int32>("topic_numbers", 1000); 
  Rate loop_rate(1);  
  int number = 1;          
  while (ok())        
  {
	std_msgs::Int32 num;   
	num.data = number;    
    number++;             
	numbers_pub.publish(num); 
	spinOnce();      
	loop_rate.sleep();    
  }

  return 0;
}