cmake_minimum_required(VERSION 3.17)
project(untitled1 C)

set(CMAKE_C_STANDARD 90)

add_executable(untitled1 main.c patientList.c patientList.h doctorList.c doctorList.h departmentList.c departmentList.h functionTest.c functionTest.h test.c)