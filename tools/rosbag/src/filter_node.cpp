#include "ros/ros.h"
#include "rosbag/message_instance.h"
#include "rosbag/view.h"
#include "rosbag/bag.h"

#if !defined(_MSC_VER)
  #include <sys/select.h>
#endif

#include <boost/foreach.hpp>
#include <boost/format.hpp>
#include <vector>
#include <string>

#define foreach BOOST_FOREACH


using std::vector;
using std::string;
using ros::Exception;
using rosbag::View;
using rosbag::Bag;
using rosbag::MessageInstance;
using rosbag::BagException;

void print_msges(const Bag& bag, const string& node_name) {
    View view(bag);
    foreach(MessageInstance m, view) {
        if (m.getCallerId() == node_name) {
            std::cout << m.getTopic() << " " << m.getTime().sec << " " << m.getTime().nsec << std::endl;
        }
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "filter_node", ros::init_options::AnonymousName);

    if (argc != 3) {
        ROS_INFO("usage: filter_node file node");
        return 1;
    }

    try {
        Bag bag(argv[1]);
        print_msges(bag, argv[2]);
    } catch(BagException& e) {
        std::cerr << "Error creating bag: " << e.what();
    } catch(Exception& e) {
        std::cerr << "Error: " << e.what();
    }
    return 0;
}
