#include "header.h"

Point::Point(double xpos, double ypos, double theta, ros::Time t)
{
  x = xpos;
  y = ypos;
  angle = theta;
  time = t;
}

Point::~Point()
{
}

double Point::getAngle(Point* target)
{
  return atan2((target->y - y),(target->x - x));
}

double Point::getDistance(Point* target)
{
  return sqrt((pow(target->y - y,2.0)) + (pow(target->x - x,2.0)));
}
