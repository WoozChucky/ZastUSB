#if __WIN32
#include "../Headers/Windows/SerialPort.h"
#include <lusb0_usb.h>
#endif
#if __UNIX

#endif

#include <iostream>
#include "../Headers/USBManager.h"


using namespace std;

int main() {

    USBManager * usbManager = new USBManager();

    try {

        usbManager->initialize();

        usbManager->scanDevices();

        usbManager->connect(0); // connects to device with index 0, assuming it exists for now

        usbManager->writeData((unsigned char *) "Vou para casa lole");

        usbManager->closeDevice();

        usbManager->shutdown();

    } catch (unsigned char * exception) {
        std::cout << exception << endl;
    }

    delete usbManager;

    return 0;
}