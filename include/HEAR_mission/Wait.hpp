#pragma once
#include "HEAR_mission/MissionElement.hpp"
#include "HEAR_core/Timer.hpp"

class Wait : public MissionElement {
public:
	int wait_time_ms;
    void perform();
    void process(DataMsg* t_msg, Port* t_port) {};
    Wait();
    ~Wait();
};