#pragma once

#include <vector>
#include "HEAR_core/DataMsg.hpp"
#include "HEAR_control/PID_values.hpp"
#include "HEAR_control/MRFT_values.hpp"
#include "HEAR_control/BB_values.hpp"
#include "HEAR_core/common_types.hpp"

class ControllerMsg : public DataMsg {
public:
    block_id id;
    PID_parameters pid_param;
    MRFT_parameters mrft_param;
    BB_parameters bb_param;
    const int getSize() {return sizeof(*this);};
    msg_type getType() {msg_type::UPDATECONTROLLER;};
    ControllerMsg() {};
    ~ControllerMsg() {};
};