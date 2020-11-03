#pragma once
#include "HEAR_core/Block.hpp"
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"

class Controller : public Block {
private:
    block_type _type;
public:
    block_type getType();
    virtual void process(DataMsg* t_msg, Port* t_port) = 0;
    Controller();
    ~Controller();
};