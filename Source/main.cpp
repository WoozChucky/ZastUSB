#if __WIN32
#include "../Headers/Windows/SerialPort.h"
#include <lusb0_usb.h>
#endif
#if __UNIX
#include "../Headers/Unix/SerialPort.h"
#endif

#include <iostream>



int main() {

    struct usb_bus *busses;

    usb_init();
    usb_find_busses();
    usb_find_devices();

    busses = usb_get_busses();
    usb_set_debug(3);
    struct usb_bus *bus;
    int  c, i, a;
    for (bus = busses; bus; bus->next){
        struct usb_device *dev;

        for (dev = bus->devices; dev; dev = dev->next){
            if (dev->descriptor.bDeviceClass == 7){
                usb_dev_handle usb_open(struct usb_device *dev);
                int usb_set_configuration(usb_dev_handle *dev, int configuration);
            }
        }
    }

    /*
    SerialPort *p = new SerialPort();
    p->connect();

    unsigned char *buffer = (unsigned char *) "Teste";

    int result = p->sendData(buffer, sizeof(buffer));

    if(result == -1) {
        //printf("Write was ok!\n");
        perror("Write Error: ");
        GetLastError();
    }

    if(p != nullptr) {

    }

    std::cout << "RESULT ->" << result << std::endl;

    std::cout << "Hello, World!" << std::endl;
    */
    return 0;
}