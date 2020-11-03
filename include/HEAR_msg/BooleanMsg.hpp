#pragma once
#include "common_srv/DataMsg.hpp"

class BooleanMsg : public DataMsg{

public:

    BooleanMsg();
    ~BooleanMsg();

    msg_type getType();
    const int getSize();

    bool data;
};