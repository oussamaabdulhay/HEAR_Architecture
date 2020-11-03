#pragma once
#include "common_srv/DataMsg.hpp"

class IntegerMsg : public DataMsg
{
public:

    IntegerMsg();
    ~IntegerMsg();

    msg_type getType();
    const int getSize();

    int data;
    
};