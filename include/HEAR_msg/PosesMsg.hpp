#pragma once
#include "HEAR_core/DataMsg.hpp"
#include "HEAR_math/Poses.hpp"

class PosesMsg : public DataMsg {
public:
    PosesMsg();
    ~PosesMsg();
    msg_type getType() {return msg_type::POSES;};
    const int getSize() {return sizeof(*this);};
    Poses p;
};