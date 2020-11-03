// Version: 3.0
// Author: P. Silva
// Last Modified By: M. Wahbah
// Date: 3 Nov 2020

#pragma once
#include <vector>
#include <iterator> 
#include "HEAR_core/MsgReceiver.hpp"

class MsgReceiver;
class MsgEmitter{
private:

protected:
    std::vector<MsgReceiver*> _list_of_msg_receivers;
public:
    MsgEmitter();
    ~MsgEmitter();
    void addCallbackMsgReceiver(MsgReceiver* _callback_msg_receiver);
    void emitMsg(DataMsg* t_msg);
};
