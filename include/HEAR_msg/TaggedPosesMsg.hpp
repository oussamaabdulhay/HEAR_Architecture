#pragma once
#include "HEAR_core/DataMsg.hpp"
#include "HEAR_math/TaggedPoses.hpp"

class TaggedPosesMsg : public DataMsg {
public:
    TaggedPosesMsg();
    ~TaggedPosesMsg();
    msg_type getType() {return msg_type::TAGGEDPOSES;};
    const int getSize() {return sizeof(*this);};
    TaggedPoses tagged_poses;
};