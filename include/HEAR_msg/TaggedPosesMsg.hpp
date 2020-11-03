#pragma once
#include "HEAR_core/DataMsg.hpp"
#include "HEAR_math/TaggedPoses.hpp"

class TaggedPosesMsg : public DataMsg {
public:
    TaggedPosesMsg();
    ~TaggedPosesMsg();
    msg_type getType();
    const int getSize();
    TaggedPoses tagged_poses;
};