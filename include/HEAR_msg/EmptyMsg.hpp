#pragma once
#include "HEAR_core/DataMsg.hpp"

class EmptyMsg : public DataMsg {
public:
    EmptyMsg() {};
    ~EmptyMsg() {};
    msg_type getType() {return msg_type::EMPTY;};
    const int getSize() {return sizeof(EmptyMsg);}
};