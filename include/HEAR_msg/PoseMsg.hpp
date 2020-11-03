#pragma once
#include "HEAR_core/DataMsg.hpp"
#include "HEAR_math/Pose.hpp"

class PoseMsg : public DataMsg{

public:
    PoseMsg();
    ~PoseMsg();
    msg_type getType();
    const int getSize();
    Pose pose;
};