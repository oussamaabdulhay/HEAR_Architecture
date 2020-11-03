#pragma once
#include "HEAR_core/DataMsg.hpp"

class BooleanMsg : public DataMsg {
public:
    BooleanMsg() {};
    ~BooleanMsg() {};
    msg_type getType() {return msg_type::BOOLEAN;};
    const int getSize() {return sizeof(BooleanMsg);};
    bool data;
};