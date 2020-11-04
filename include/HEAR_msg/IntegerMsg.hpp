#pragma once
#include "HEAR_core/DataMsg.hpp"

class IntegerMsg : public DataMsg
{
public:
    IntegerMsg() {};
    ~IntegerMsg() {};
    msg_type getType() {return msg_type::INTEGER;};
    const int getSize() {return sizeof(IntegerMsg);};
    int data;
};