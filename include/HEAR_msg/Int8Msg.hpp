#pragma once
#include "HEAR_core/DataMsg.hpp"

class Int8Msg : public DataMsg {
public:
    uint8_t data;
    msg_type getType() {return msg_type::INT8;};
    const int getSize() {return sizeof(*this);};
    Int8Msg() {};
    ~Int8Msg() {};
};