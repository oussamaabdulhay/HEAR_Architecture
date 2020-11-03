#pragma once
#include "common_srv/DataMsg.hpp"

class DoubleMsg : public DataMsg
{
public:

    DoubleMsg();
    ~DoubleMsg();

    msg_type getType();
    const int getSize();

    double data;
    
};