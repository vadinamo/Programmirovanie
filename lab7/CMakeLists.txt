cmake_minimum_required(VERSION 3.17)
project(untitled1 C)

set(CMAKE_C_STANDARD 90)

add_executable(untitled1 main.c departmentList.c departmentList.h doctorList.c doctorList.h patientList.c patientList.h)