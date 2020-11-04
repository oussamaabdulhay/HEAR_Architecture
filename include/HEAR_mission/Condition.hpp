#pragma once
#include "HEAR_core/Block.hpp"

class Condition :public Block {
public:
    virtual bool isConditionMet()=0;
    virtual void process(DataMsg* t_msg, Port* t_port) = 0;    
};