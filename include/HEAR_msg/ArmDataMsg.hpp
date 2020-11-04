#pragma once
#include "HEAR_core/DataMsg.hpp"

class ArmDataMsg: public DataMsg {
public:
    ArmDataMsg();
    ~ArmDataMsg();
    msg_type getType() {return msg_type::arm_update;};
    const int getSize() {return sizeof(*this);};
    bool isArmed=false;
};