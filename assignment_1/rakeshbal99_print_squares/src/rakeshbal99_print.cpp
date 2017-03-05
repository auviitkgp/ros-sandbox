#include "ros/ros.h"                   
#include "std_msgs/Int32.h"
using namespace ros;                     
                      

  void callback_topic_numbers(const std_msgs::Int32::ConstPtr& num)    
    {
    ROS_INFO("topic_numbers : [%d]\n ",num->data);
    }

  void callback_topic_squares(const std_msgs::Int32::ConstPtr& square)    
    {
    ROS_INFO("topic_squares : [%d]\n",square->data);
    }


  int main(int argc,char **argv)
  {
    init(argc, argv, "rakeshbal99_print"); 
    NodeHandle N1, N2;                   
    Rate loop_rate(1);
    Subscriber sub1 = N1.subscribe("topic_numbers", 777, callback_topic_numbers);
    loop_rate.sleep();
    Subscriber sub2 = N2.subscribe("topic_squares", 777, callback_topic_squares);
    spin();
    return 0;
  }