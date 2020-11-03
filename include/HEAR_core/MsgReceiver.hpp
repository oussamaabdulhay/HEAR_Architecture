// Version: 3.0
// Author: P. Silva
// Last Modified By: M. Wahbah
// Date: 3 Nov 2020
#pragma once

#include "HEAR_core/DataMsg.hpp"

class MsgReceiver {

public:
    MsgReceiver();
    virtual void receiveMsgData(DataMsg* t_msg) = 0;
};