#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Int64.h>
#include <math.h>

void chatterCallback(const std_msgs::Int64::ConstPtr& msg)
{ 
  long int i;
  ros::NodeHandle n;
  //advertising on topic_squares
  ros::Publisher topic_squares_pub = n.advertise<std_msgs::Int64>("topic_squares", 1000);
  
  //taking the square
  i = msg->data * msg->data;
  std_msgs::Int64 msg1;
  msg1.data = i;

  //publishing on topic topic_squares
  topic_squares_pub.publish(msg1);
  ros::spin();

}

int main(int argc, char **argv)
{
  //initializing the node square
  ros::init(argc, argv, "square");
  ros::NodeHandle n;

  //subscribing to the topic topic_numbers
  ros::Subscriber sub = n.subscribe("topic_numbers", 1000, chatterCallback);

  ros::spin();

  return 0;
}
