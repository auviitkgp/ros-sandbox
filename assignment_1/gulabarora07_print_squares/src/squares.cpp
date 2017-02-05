#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>
#include <stdlib.h>

int count=1;
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  int a = atoi(msg->data.c_str());

  count=a*a;
}
int main(int argc, char **argv)
{  
  ros::init(argc, argv, "squares");
  
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("topic_squares", 1000);

  ros::Subscriber sub = n.subscribe("topic_numbers", 1000, chatterCallback);

  ros::Rate loop_rate(1);

  while(ros::ok())
  {
    std_msgs::String msg;

    std::stringstream ss;

    ss << count;

    msg.data = ss.str();

    chatter_pub.publish(msg);

    loop_rate.sleep();

    ros::spinOnce();
  }
  ros::spin();

  return 0;
}

