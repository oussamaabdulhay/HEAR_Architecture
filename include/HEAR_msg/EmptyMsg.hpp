#pragma once
#include "common_srv/DataMsg.hpp"

class EmptyMsg : public DataMsg
{
public:

    EmptyMsg();
    ~EmptyMsg();

    msg_type getType();
    const int getSize();    
};