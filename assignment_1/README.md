Assignment 1
============

Problem statement:

Create a catkin package `print_squares` which contains three nodes `numbers`, `squares`, `print`.
- `numbers` - This node will publish natural numbers to a ROS topic named `topic_numbers` at the rate of 1 Hz.
- `squares` - This node will subscribe to `topic_numbers` and print the squares of the published numbers to another topic, `topic_squares`.
- `print` - This node will subscribe to both `topic_numbers` and `topic_squares` and output them using ROS_INFO.

Instructions for submission:
- The programs must use C++ API of ROS.
- Your catkin package should be named `<your_github_username>` and placed under `<repo_root>/assignment_1/`
