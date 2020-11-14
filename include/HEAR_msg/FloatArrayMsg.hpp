#pragma once
#include "HEAR_core/DataMsg.hpp"

class FloatArrayMsg : public DataMsg
{
public:
    FloatArrayMsg() {};
    ~FloatArrayMsg() {};
    msg_type getType() {return msg_type::FLOATARRAY;};
    const int getSize() {return sizeof(*this);};
    std::vector<float> data;
};