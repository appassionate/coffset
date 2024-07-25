#本项目的CMakeLists.txt

# set(CMAKE_FIND_DEBUG_MODE 1) 

cmake_minimum_required(VERSION 3.0)
project(filereader)
# find_package(fmt CONFIG REQUIRED)

include_directories(./include/)

# 添加源文件
# add_library(util STATIC ./src/util.cpp)


add_executable(main ./main.cpp)
add_executable(test ./test.cpp)