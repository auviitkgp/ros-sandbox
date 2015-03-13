#include "ros/ros.h"
#include "std_msgs/String.h"
int square_i=1;
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  int i = atoi(msg->data.c_str());
	square_i= i*i;
}


int main(int argc, char **argv)
{

  ros::init(argc, argv, "squares_kaustubhhiware");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("topic_numbers",1000);
  ros::Subscriber sub = n.subscribe("topic_numbers", 1000, chatterCallback);

  ros::Rate loop_rate(1);
while (ros::ok())
  {
    std_msgs::String msg;
    std::stringstream ss;
    ss << square_i;
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);
    
    loop_rate.sleep();
	ros::spinOnce();
  }


  ros::spin();
  return 0;
}


