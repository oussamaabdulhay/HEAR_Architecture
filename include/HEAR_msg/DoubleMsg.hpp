#pragma once
#include "HEAR_core/DataMsg.hpp"

class DoubleMsg : public DataMsg {
public:
    DoubleMsg() {};
    ~DoubleMsg() {};
    msg_type getType() {return msg_type::DOUBLE;};
    const int getSize() {return sizeof(DoubleMsg);};
    double data;
};