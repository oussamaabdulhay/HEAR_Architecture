#pragma once
#include "HEAR_core/DataMsg.hpp"

class FloatMsg : public DataMsg
{
public:
    FloatMsg();
    ~FloatMsg();
    msg_type getType();
    const int getSize();
    float data;
};