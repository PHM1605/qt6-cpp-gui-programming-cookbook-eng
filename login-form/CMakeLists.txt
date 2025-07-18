cmake_minimum_required(VERSION 3.16)
project(login-form LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(login-form
  src/main.cpp 
)

target_link_libraries(login-form Qt6::Widgets)
