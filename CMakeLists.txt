cmake_minimum_required(VERSION 3.7)
project(ZastUSB)

set(CMAKE_CXX_STANDARD 14)

if(WIN32)
    set(SOURCE_FILES Source/main.cpp Source/Windows/SerialPort.cpp Headers/Windows/SerialPort.h)
    add_definitions(-D__WIN32)
endif (WIN32)

if(UNIX)
    set(SOURCE_FILES Source/main.cpp Source/Unix/SerialPort.cpp Headers/Unix/SerialPort.h)
    add_definitions(-D__UNIX)
endif (UNIX)

add_executable(ZastUSB ${SOURCE_FILES})
