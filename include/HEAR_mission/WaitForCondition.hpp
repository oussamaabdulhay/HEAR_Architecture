#pragma once

#include <unistd.h>
#include "HEAR_mission/Condition.hpp"
#include "HEAR_mission/MissionElement.hpp"

class WaitForCondition : public MissionElement{
private:
	Condition* m_wait_condition;
public:
    void perform();
    WaitForCondition(Condition*);
    void process(DataMsg* t_msg, Port* t_port) {};
};