#include "ros/ros.h"
#include <std_msgs/Int64.h>
#include "std_msgs/String.h"
#include <sstream>
#include<stdlib.h>

using namespace std;
using namespace ros;
using namespace std_msgs;

int main(int argc, char **argv)
{  
  //Initialise node number
  init(argc, argv, "number");
  NodeHandle n1;
  //advertising
  Publisher topic_numbers_pub = n1.advertise<std_msgs::Int64>("topic_numbers", 1000);
  Rate loop_rate(1);
  int n=1;
  while (ok())
  {
    std_msgs::Int64 msg;
    msg.data =n;
    ROS_INFO("%d", msg.data); 
    //Publishing on topicnumber   
    topic_numbers_pub.publish(msg);
    spinOnce();
    loop_rate.sleep();
    ++n;    
  }
  return 0;
}
