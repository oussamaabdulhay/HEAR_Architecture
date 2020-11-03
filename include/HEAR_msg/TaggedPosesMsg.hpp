#pragma once
#include "common_srv/DataMsg.hpp"
#include "common_srv/Vector3D.hpp"
#include "common_srv/PoseMsg.hpp"
#include "common_srv/TaggedPoses.hpp"
#include <vector>

class TaggedPosesMsg : public DataMsg
{

public:

    TaggedPosesMsg();
    ~TaggedPosesMsg();
    msg_type getType();
    const int getSize();

    TaggedPoses tagged_poses;
};