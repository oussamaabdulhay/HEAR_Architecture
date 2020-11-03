#pragma once
#include "common_srv/DataMsg.hpp"
#include "common_srv/Pose.hpp"

class PoseMsg : public DataMsg{

public:

    PoseMsg();
    ~PoseMsg();
    msg_type getType();
    const int getSize();

    Pose pose;
};