// Version: 2.0
// Author: P. Silva
// Last Modified By: M. Wahbah
// Date: 3 Nov 2020

#pragma once
#include <list>
#include "HEAR_msg/msg_types.hpp"

class DataMsg {

public:
    
    virtual msg_type getType() = 0;
    virtual const int getSize() = 0;

    DataMsg() {};
    ~DataMsg() {};
};