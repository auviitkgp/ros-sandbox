#include "ros/ros.h"
#include "std_msgs/Int64.h"

ros::Publisher sqr_pub;
std_msgs::Int64 sqr;

void NumberCallback(const std_msgs::Int64::ConstPtr& msg)
{
  sqr.data = ((msg->data)*(msg->data));

  if(ros::ok())
    {
      sqr_pub.publish(sqr);
      ROS_INFO("The number published is %ld",sqr.data);
    }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "arijitkar98_squares");

  ros::NodeHandle sqr;

  ros::Subscriber num_sub = sqr.subscribe("topic_numbers", 1000, NumberCallback);
  sqr_pub = sqr.advertise<std_msgs::Int64>("topic_squares",1000);

  ros::Rate loop_rate(1);

  ros::spin();

  return 0;
}
