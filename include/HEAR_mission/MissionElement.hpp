#pragma once

#include "HEAR_core/Block.hpp"
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"

class MissionElement : public Block {
public:
    virtual void perform() = 0;
    virtual void process(DataMsg* t_msg, Port* t_port) = 0;
    MissionElement() {};
    ~MissionElement() {};
};