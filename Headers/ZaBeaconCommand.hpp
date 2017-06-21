//
// Created by root on 21-06-2017.
//

#ifndef ZASTUSB_ZABEACONCOMMAND_HPP
#define ZASTUSB_ZABEACONCOMMAND_HPP

#include <string>

struct ZaBeaconCommand {

    int operationType; //0 - Open/ 1 - Validate / 2 - Configure
    int checkinType; //0 - In / 1 - Out
    std::string deviceId;
    std::string transationDateTime;
    unsigned long operatorId;
    std::string lineDirection;
    std::string seatNumber; //It is a string because it can have letters associated
};

enum { OPERATION_TYPE_OPEN = 0, OPERATION_TYPE_VALIDATE = 1, OPERATION_TYPE_CONFIGURE = 2};

#endif //ZASTUSB_ZABEACONCOMMAND_HPP

