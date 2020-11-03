#pragma once
#include "HEAR_core/DataMsg.hpp"
#include "HEAR_math/Poses.hpp"

class PosesMsg : public DataMsg {
public:
    PosesMsg();
    ~PosesMsg();
    msg_type getType();
    const int getSize();
    Poses p;
};