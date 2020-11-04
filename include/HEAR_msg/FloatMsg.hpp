#pragma once
#include "HEAR_core/DataMsg.hpp"

class FloatMsg : public DataMsg
{
public:
    FloatMsg() {};
    ~FloatMsg() {};
    msg_type getType() {return msg_type::FLOAT;};
    const int getSize() {return sizeof(FloatMsg);};
    float data;
};