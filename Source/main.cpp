#if __WIN32

#endif
#if __UNIX
#include "../Headers/Unix/SerialPort.h"
#endif

#include <iostream>



int main() {

    SerialPort *p = new SerialPort();
    p->connect();

    unsigned char *buffer = (unsigned char *) "Teste";

    int result = p->sendData(buffer, sizeof(buffer));

    if(result == -1) {
        //printf("Write was ok!\n");
        perror("Write Error: ");
    }

    if(p != nullptr) {

    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}