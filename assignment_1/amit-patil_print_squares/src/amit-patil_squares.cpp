/*
includes all the necessary libraries required for common use. 
*/
#include <ros/ros.h>
#include "std_msgs/Int32.h"

//new class
class square
{
public:
  square()
  {
    pub = n.advertise<std_msgs::Int32>("/topic_squares", 1);//publishes square to topic 'topic_squares'    
    sub = n.subscribe("/topic_numbers", 1, &square::callback, this);//subscribes to 'topic_number'
  }

  void callback(const std_msgs::Int32::ConstPtr& input)
  {
    std_msgs::Int32 output;//output of type int64
    output.data = input->data*input->data;//square the input
    pub.publish(output);
  }

private:
  ros::NodeHandle n; 
  ros::Publisher pub;
  ros::Subscriber sub;

};


int main(int argc, char **argv)
{
  ros::init(argc, argv, "amit-patil_squares");//initializes ros and node 'amit-patil_squares'
  square new_obj;//object created from class square
  ros::spin();//process when node is shut down
  return 0;
}
