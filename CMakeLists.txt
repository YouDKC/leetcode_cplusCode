cmake_minimum_required(VERSION 3.10)
#https://blog.csdn.net/gaowu959/article/details/78484725
project(cplusCode)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x")

# 引入子目录
ADD_SUBDIRECTORY(234_24games)
