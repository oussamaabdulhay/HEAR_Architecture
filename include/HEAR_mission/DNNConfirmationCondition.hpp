#pragma once
#include "HEAR_mission/Condition.hpp"
#include "HEAR_misc/common_types.hpp"
#include "HEAR_msg/IntegerMsg.hpp"
#include "HEAR_core/InputPort.hpp"
//TODO: this need refactoring - should be more general
class DNNConfirmationCondition : public Condition {
private:
    Port* _input_port_0;
	bool _isConditionMet=false;
    control_system _cs;
public:
    enum ports_id {IP_0};
    bool isConditionMet();
    void process(DataMsg* t_msg, Port* t_port);    
    DNNConfirmationCondition(control_system);
};
