//
// Created by nuno on 20-06-2017.
//

#ifndef ZASTUSB_USBMANAGER_H
#define ZASTUSB_USBMANAGER_H

#include <iostream>
#include <vector>
#include <libusb-1.0/libusb.h>

#define ITERATE true

using namespace std;

class USBManager {
private:
    libusb_context *context = nullptr;
    libusb_device_handle *device_handle;
    libusb_device** devices;
    unsigned char *buffer;
    int result;
    int bytesRead;
    ssize_t deviceCount;

    void printDeviceInfo(libusb_device *dev);

public:
    USBManager();
    ~USBManager();
    void initialize();
    void scanDevices();
    void closeDevice();
    void shutdown();
    void writeData(unsigned char * message);
    void pickDevice(); //this is only used while we don't have a permanent USB device information
    void connect(int index); // public for now
};

#endif //ZASTUSB_USBMANAGER_H
