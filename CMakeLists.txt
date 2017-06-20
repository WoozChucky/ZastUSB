cmake_minimum_required(VERSION 3.7)
project(ZastUSB)

set(CMAKE_CXX_STANDARD 14)



if(WIN32)
    set(SOURCE_FILES Source/main.cpp Source/Windows/SerialPort.cpp Headers/Windows/SerialPort.h)
    add_definitions(-D__WIN32)
    INCLUDE_DIRECTORIES(Includes/Windows)
endif (WIN32)

if(UNIX)
    set(SOURCE_FILES Source/main.cpp Source/Unix/SerialPort.cpp Headers/Unix/SerialPort.h)
    add_definitions(-D__UNIX)
    INCLUDE_DIRECTORIES(Includes/Unix)

    add_executable(ZastUSB ${SOURCE_FILES})

    target_include_directories(ZastUSB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Includes/Unix/libusb-1.0)

    target_link_libraries(ZastUSB usb-1.0)
endif (UNIX)






