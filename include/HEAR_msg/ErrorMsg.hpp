#pragma once

#include "HEAR_core/DataMsg.hpp"

class ErrorMsg : public DataMsg {
public:
    bool error = false;
    msg_type getType() {return msg_type::ERROR;};
	const int getSize() {return sizeof(ErrorMsg);};

};