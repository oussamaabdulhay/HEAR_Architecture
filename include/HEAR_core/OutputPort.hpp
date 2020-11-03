#pragma once
#include "HEAR_core/Port.hpp"

class OutputPort : public Port{

private:
    DataMsg* _data;
    int _id;
    Block* _block;

public:
    
    void receiveMsgData(DataMsg* t_msg);
    OutputPort(int t_id, Block* t_block);
    ~OutputPort();
};