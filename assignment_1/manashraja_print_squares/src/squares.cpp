#include <ros/ros.h>
#include "std_msgs/Int32.h"

class Square_Publish
{
public:
  Square_Publish()
  {
    pub_ = n_.advertise<std_msgs::Int32>("/topic_squares", 1);
    
    sub_ = n_.subscribe("/topic_numbers", 1, &Square_Publish::callback, this);
  }

  void callback(const std_msgs::Int32::ConstPtr& input)
  {
    std_msgs::Int32 output;

    output.data = input->data*input->data;
    pub_.publish(output);
  }

private:
  ros::NodeHandle n_; 
  ros::Publisher pub_;
  ros::Subscriber sub_;

}; //End of class Square_Publish

int main(int argc, char **argv)
{
  ros::init(argc, argv, "squares");
  Square_Publish NewObject;

  ros::spin();

  return 0;
}