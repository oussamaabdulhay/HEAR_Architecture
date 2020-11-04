#pragma once
#include "HEAR_core/DataMsg.hpp"

class InfoMsg : public DataMsg{
public:
    bool armed;
    int number_of_waypoints;
    msg_type getType() {return msg_type::INFO;};
	const int getSize() {return sizeof(InfoMsg);};
};