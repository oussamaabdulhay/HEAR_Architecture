#pragma once
#include "HEAR_core/DataMsg.hpp"
#include "HEAR_math/Pose.hpp"

class PoseMsg : public DataMsg{

public:
    PoseMsg() {};
    ~PoseMsg() {};
    msg_type getType() {return msg_type::POSE;};
    const int getSize() {return sizeof(PoseMsg);};
    Pose pose;
};