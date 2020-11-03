#pragma once
#include "HEAR_core/Port.hpp"

class InputPort : public Port {

private:
    DataMsg* _data;
    int _id;
    Block* _block;

public:
    
    void receiveMsgData(DataMsg* t_msg);
    InputPort(int t_id, Block* t_block);
    ~InputPort();
};