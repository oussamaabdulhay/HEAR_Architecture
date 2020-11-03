#pragma once
#include "common_srv/DataMsg.hpp"

class FloatMsg : public DataMsg
{
public:

    FloatMsg();
    ~FloatMsg();

    msg_type getType();
    const int getSize();

    float data;
    
};