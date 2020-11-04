#pragma once
#include "HEAR_core/DataMsg.hpp"

class MissionCommandMsg : public DataMsg {
public:
    msg_type getType() {return msg_type::MISSIONCOMMAND;};
    const int getSize() {return sizeof(*this);};
    int data;
    MissionCommandMsg();
    ~MissionCommandMsg();
};