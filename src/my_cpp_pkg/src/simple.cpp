#include "rclcpp/rclcpp.hpp"

class SimpleNode : public rclcpp::Node
{
    public:
	SimpleNode() : Node("simplenode") {}

};

int main(int argc, char* argv[])
{
  (void) argc;
  (void) argv;

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SimpleNode>());
  rclcpp::shutdown();

  return 0;
}
