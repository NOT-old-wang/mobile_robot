cmake_minimum_required(VERSION 3.5.1)
project(common)

add_compile_options(-std=c++11)

# 开启 test.cc 编译
set(TEST on)

# 外部库调用
# 谷歌protopuf库
find_package(protobuf CONFIG REQUIRED)
# protobuf::libprotobuf

# boost库
find_package(Boost REQUIRED COMPONENTS system)

# eigen矩阵库
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
# include_directories("/usr/include/eigen3")

# 加密计算库
find_package(OpenSSL REQUIRED COMPONENTS system)
# ${OPENSSL_LIBRARIES}

# OpenCv库
# find_package(OpenCV REQUIRED)
# include_directories(${OpenCV_INCLUDE_DIRS})
# ${OpenCV_LIBS}

# Google Ceres库
# find_package(Ceres REQUIRED PATHS ${PROJECT_SOURCE_DIR}/lib)
# include_directories(
#   ${PROJECT_SOURCE_DIR}/lib/include
# )
# ${CERES_LIBRARIES}

# 头文件
include_directories(${PROJLECT_NAME}
  math/
  socket/
  util/
  proto/cpp_out/
)

# 编译成库
add_library(${PROJECT_NAME}
  proto/cpp_out/demo.pb.cc
)

# 自己测试用
if (TEST)
add_executable(${PROJECT_NAME}_test test.cc)
target_link_libraries(${PROJECT_NAME}_test 
  ${PROJECT_NAME}
  protobuf::libprotobuf
)
endif (TEST)


# syntax = "proto3";

# package common;

# message Req{
#     int32 subReqID = 1;
#     string userName = 2;
#     string productName = 3;
#     repeated string address = 4;
# }
