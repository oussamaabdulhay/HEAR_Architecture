#pragma once

#include "HEAR_core/DataMsg.hpp"

class ResetControllerMsg: public DataMsg {
public:
    block_id target_block;
    msg_type getType() {return msg_type::RestControllerMessage;};
    const int getSize() {return sizeof(*this);};
    ResetControllerMsg() {};
    ~ResetControllerMsg() {};
};