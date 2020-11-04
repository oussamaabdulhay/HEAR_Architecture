#pragma once
#include "HEAR_core/Block.hpp"
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"

class Controller : public Block {
public:
    //TODO: getType might be depricated
    block_type getType() {return block_type::controller;};
    virtual void process(DataMsg* t_msg, Port* t_port) = 0;
    Controller(){};
    ~Controller(){};
};