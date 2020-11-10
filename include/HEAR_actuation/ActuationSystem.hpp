#pragma once

#include <vector>
#include "HEAR_actuation/Actuator.hpp"
#include "HEAR_core/Block.hpp"
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"

class ActuationSystem : public Block {
public:
    ActuationSystem(std::vector<Actuator*>) {};
    virtual void setESCValues(int, int, int) = 0;
    virtual void process(DataMsg* t_msg, Port* t_port) = 0;
};