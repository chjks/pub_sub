#include <ros/ros.h>
#include <std_msgs/Int32.h>

void callback(const std_msgs::Int32::ConstPtr& msg) {
    ROS_INFO("Yes, received : [%d]", msg->data);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "sub_node"); // ROS 노드 초기화
    ros::NodeHandle nh; // 노드 핸들 생성

    ros::Subscriber sub = nh.subscribe("topic", 1000, callback);

    ros::spin(); // 콜백 함수 대기
    return 0;
}
