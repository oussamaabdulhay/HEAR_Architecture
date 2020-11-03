#pragma once
class Port;
#include "HEAR_core/Block.hpp"
#include "HEAR_core/MsgReceiver.hpp"
#include "HEAR_core/MsgEmitter.hpp"

class Port : public MsgReceiver, public MsgEmitter{

private:
    int _id;
    Block* _block;

public:
    
    virtual void receiveMsgData(DataMsg* t_msg) = 0;
    int getID();
    void connect(Port*);
    Port(int t_id, Block* t_block);
    ~Port();
};