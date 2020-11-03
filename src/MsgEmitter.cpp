#include "HEAR_core/MsgEmitter.hpp"
using namespace std;


MsgEmitter::MsgEmitter() {
}

MsgEmitter::~MsgEmitter() {

}

void MsgEmitter::addCallbackMsgReceiver(MsgReceiver* _callback_msg_receiver){
    _list_of_msg_receivers.push_back(_callback_msg_receiver);
}

void MsgEmitter::emitMsg(DataMsg* t_msg) {
    for (int i = 0; i < _list_of_msg_receivers.size(); ++i){
        _list_of_msg_receivers[i]->receiveMsgData(t_msg);
    }
}