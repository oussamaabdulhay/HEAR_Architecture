#pragma once
#include "HEAR_core/DataMsg.hpp"
#include "HEAR_math/Quaternion.hpp"

class QuatMsg : public DataMsg {
public:
    Quaternion data;
    msg_type getType() {return msg_type::QUAT;};
    const int getSize() {return sizeof(*this);};
    QuatMsg() {};
    ~QuatMsg() {};
};