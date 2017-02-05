# Assignment 1
## Problem statement:

Create a `catkin` (or `rosbuild`) package `<github-username>_print_squares` which contains three nodes `numbers`, `squares`, `print`.
- `numbers` - This node will publish integers (starting from 1) to a ROS topic named `topic_numbers` at the rate of 1 Hz.
- `squares` - This node will subscribe to `topic_numbers` and print the squares of the published numbers to another topic, `topic_squares`.
- `print` - This node will subscribe to both `topic_numbers` and `topic_squares` and output them using ROS_INFO. The output will indicate the name of the topic that the output has come from. 

### Instructions: The development process
- The programs must use the C++ API of ROS.
- If the code is copied from the ROS website, You must not copy any documentation present in it. 
- The code **MUST** be documented. You must write this documentation yourself. This documentation may be written in any form that you think is appropriate for your code. (Line-wise, Block-wise etc.)

### Logistics
* Fork the `ros-sandbox` repository
* Create a github repository with the name `username_print_squares`.
* Create the required catkin package inside `~/catin-ws/src/` using `catkin_create_pkg`.
* Make this catkin package a git repository and ensure that it pushes to the repository created in second step.
* Once you are done with the development, place this catkin-package inside `<this-repo-root>/assignment_1/` and send a pull request.

### Final Submissions for this assignment
- Pull Request to `auviitkgp/ros-sandbox` containin the package `<this-repo-root>/assignment_1/username_print_squares/`
- GitHub Repo: `github.com/username/username_print_squares`

