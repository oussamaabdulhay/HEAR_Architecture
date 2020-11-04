#pragma once
#include "HEAR_core/DataMsg.hpp"

class BoolMsg : public DataMsg {
public:
    BoolMsg() {};
    ~BoolMsg() {};
    msg_type getType() {return msg_type::BOOLEAN;};
    const int getSize() {return sizeof(BoolMsg);};
    bool data;
};