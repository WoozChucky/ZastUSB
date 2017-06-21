//
// Created by root on 21-06-2017.
//

#ifndef ZASTUSB_UDPSERVER_H
#define ZASTUSB_UDPSERVER_H

#define MAX_LENGTH 1024

#include <boost/asio.hpp>
#include <iostream>
#include <cstdlib>
#include "ZaBeaconCommand.hpp"
#include "USBManager.h"

using boost::asio::ip::udp;

class UDPServer {
private:
    // variables
    udp::socket _socket;
    udp::endpoint _senderEndpoint;
    char _buffer[MAX_LENGTH] = "";
    ZaBeaconCommand _command;
    USBManager * _usbManager;

    // methods
    void listen();
    void send(std::size_t length);
    void send(std::string message);
public:
    UDPServer(boost::asio::io_service& io_service, unsigned short port);
    ~UDPServer();
};

#endif //ZASTUSB_UDPSERVER_H
