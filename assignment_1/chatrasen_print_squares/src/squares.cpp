/*
*******************************************************
This is the node named squares.
This will subscribe to the topic "topic_numbers and
will publish on the topic "topic_squares"
*******************************************************
*/

#include "ros/ros.h" 
#include "std_msgs/String.h"  //we will publish msgs in the form of strings
#include <sstream>


using namespace ros;
using namespace std_msgs;
using namespace std;
   

 void topic_numbers_Callback(const std_msgs::String::ConstPtr& msg)  //Each time we receice a subscibed msg, we enter this function
  {
    NodeHandle p;  //a node created to publish
    Publisher topic_squares_pub = p.advertise<String>("topic_squares", 1000); 
    
    Rate loop_rate(1);
    
    int sqr;
    sqr = atoi(msg->data.c_str())*atoi(msg->data.c_str()); //String converted to integer which inturn is squared
    String msg1;
    stringstream ss;  //used to convert number to string
    ss << sqr;
    msg1.data = ss.str();
    loop_rate.sleep();
    topic_squares_pub.publish(msg1);
    spinOnce();
  }

  int main(int argc,char **argv)
  {
  	init(argc, argv, "squares");
  	NodeHandle s;
  	Subscriber sub = s.subscribe("topic_numbers", 1000, topic_numbers_Callback);
  	spin();
  	return 0;
  }
