/*
Copyright 2019 undefined

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
// #include <google/protobuf/io/coded_stream.h>
// #include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/message_lite.h>
#include <fstream>
#include <iostream>
#include "eigen3/Eigen/Dense"
#include "proto/cpp_out/demo.pb.h"
#include "util/factory.h"
#include "util/json11.h"

#define USE_STREAM 0
#define USE_STRING 1

int main(int argc, const char **argv) {
  //   modules::common::Person person_server;
  //   person_server.set_name("Wang Jy");
  //   person_server.set_id(666);
  //   person_server.set_email("wangjy@demo.com");

  //   modules::common::Person person_client;

  // #if USE_STREAM
  //   std::fstream output("wangjy_proto_demo", std::ios::out |
  //   std::ios::binary); person_server.SerializeToOstream(&output);
  //   output.close();
  //   std::fstream input("wangjy_proto_demo", std::ios::in | std::ios::binary);
  //   person_client.ParseFromIstream(&input);
  //   input.close();
  // #else if USE_STRING
  //   std::string proto_string;
  //   person_server.SerializeToString(&proto_string);
  //   person_client.ParseFromString(proto_string);
  // #endif

  //   std::cout << person_server.DebugString() << std::endl;
  //   // std::cout << "server name: " << person_server.name() << std::endl;
  //   // std::cout << "server id: " << person_server.id() << std::endl;
  //   // std::cout << "---------------------------------" << std::endl;
  //   std::cout << "client name: " << person_client.name() << std::endl;
  //   std::cout << "client id: " << person_client.id() << std::endl;

  //   modules::common::Person::PhoneNumber *phone_number1 =
  //       person_server.add_phone();
  //   phone_number1->set_number("110");
  //   phone_number1->set_type(modules::common::Person::WORK);
  //   modules::common::Person::PhoneNumber *phone_number2 =
  //       person_server.add_phone();
  //   std::cout << person_server.phone_size() << std::endl;

  //   switch (person_server.phone(0).type()) {
  //     case modules::common::Person::WORK:
  //       std::cout << "work." << std::endl;
  //       break;

  //     default:
  //       break;
  //   }

  Eigen::Vector2d current_to_next(-2, 1);
  Eigen::Vector2d next_to_next_next(-1, -1);

  double ab = std::hypot(2 - 0, 0 - 1) * std::hypot(-1 - 0, 0 - 1);
  double theta = current_to_next.dot(next_to_next_next) / ab;
  std::cout << theta << std::endl;
  return 0;
}


# if 0
#include <iostream>
#include <Eigen/Dense>

typedef Eigen::Vector3d Point;

double getDegAngle(Point p1, Point p2, Point p3) {
    Eigen::Vector3d v1 = p2 - p1;
    Eigen::Vector3d v2 = p3 - p1;
    //one method, radian_angle belong to 0~pi
    //double radian_angle = atan2(v1.cross(v2).transpose() * (v1.cross(v2) / v1.cross(v2).norm()), v1.transpose() * v2);
    //another method, radian_angle belong to 0~2pi
    double radian_angle = atan2(v1.cross(v2).norm(), v1.transpose() * v2);
    if (v1.cross(v2).z() < 0) {
        radian_angle = 2 * M_PI - radian_angle;
    }
    return radian_angle * 180 / M_PI;
}

int main() {
    //Point p1(0, 0, 0), p2(1, 0, 0), p3(0, -1, 0);
    //Point p1(0, 0, 0), p2(1, 0, 0), p3(0, 1, 0);
    //Point p1(0, 0, 0), p2(1, 0, 0), p3(0.5, 0.5, 0);
    Point p1(0, 0, 0), p2(1, 0, 0), p3(0.5, -0.5, 0);
    std::cout << "The Degree Angle is: " << getDegAngle(p1, p2, p3) << "\n";
    return 0;
}

# endif