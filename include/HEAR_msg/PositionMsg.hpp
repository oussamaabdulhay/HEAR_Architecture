#pragma once 

#include "HEAR_core/DataMsg.hpp"

class PositionMsg : public DataMsg {
public:
	msg_type getType() {return msg_type::POSITION;};
	const int getSize() {return sizeof(PositionMsg);};
	float x, y, z;	
};