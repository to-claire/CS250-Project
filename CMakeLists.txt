cmake_minimum_required(VERSION 3.23)
project(CS250_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS250_Project Main.cpp
        Course.cpp
        Course.h
        CourseList.cpp
        CourseList.h
        CourseListBigThree.cpp
        CourseListInsertInOrder.cpp
        Interface.cpp
        Interface.h
        TestingCases.cpp
        TestingCases.h)
