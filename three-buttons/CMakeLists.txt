cmake_minimum_required(VERSION 3.16)
project(three-buttons LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(three-buttons
  src/main.cpp 
)

target_link_libraries(three-buttons Qt6::Widgets)
