#include <ros/ros.h>
#include <std_msgs/Int32.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "pub_node"); // ROS 노드 초기화
    ros::NodeHandle nh; // 노드 핸들 생성
    ros::Publisher pub = nh.advertise<std_msgs::Int32>("topic", 1000);

    ros::Rate rate(10); // 10Hz
    int count = 0;

    while (ros::ok()) {
        std_msgs::Int32 msg;
        msg.data = count;

        ROS_INFO("Hi, I'm %d", count);

        pub.publish(msg); // 메시지 퍼블리시

        rate.sleep(); // 루프 속도 제어
        count++;
        if (count > 100) {
            break;
        }
    }

    return 0;
}
