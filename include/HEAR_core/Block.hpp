#pragma once
class Block;
#include <iostream>
#include <vector>
#include "HEAR_core/Port.hpp"
#include "HEAR_misc/common_types.hpp"

class Block {

    public:

        virtual void process(DataMsg* t_msg, Port* t_port) = 0;
        Block() {};
        ~Block() {};
        std::vector<Port*> getPorts() {return _ports;}

    protected:
        std::vector<Port*> _ports;
};