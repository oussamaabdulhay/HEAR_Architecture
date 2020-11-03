#pragma once
#include "common_srv/DataMsg.hpp"
#include "common_srv/Vector3D.hpp"
#include "common_srv/Poses.hpp"

class PosesMsg : public DataMsg
{

public:

    PosesMsg();
    ~PosesMsg();
    msg_type getType();
    const int getSize();

    Poses p;
};