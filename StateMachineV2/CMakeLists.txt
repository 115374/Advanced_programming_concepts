cmake_minimum_required(VERSION 3.22.1)
project(StateMachineV2)

set(CMAKE_CXX_STANDARD 23)

add_executable(StateMachineV2 main.cpp iState.h statemachine.h fridgeStates.h)
