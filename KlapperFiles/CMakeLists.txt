cmake_minimum_required(VERSION 3.5)

project(KlapperNetwork LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set( CMAKE_CXX_FLAGS "-lpqxx")
add_executable(KlapperNetwork main.cpp
node.h node.cpp
networkhandler.h networkhandler.cpp
backpropagation.h backpropagation.cpp
persistence.h persistence.cpp
traininghandler.h traininghandler.cpp
)
