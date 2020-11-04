#pragma once
#include "internal_states.hpp"
#include "HEAR_mission/MissionElement.hpp"
#include "HEAR_msg/IntegerMsg.hpp"
#include "MissionStateManager.hpp"

class ChangeInternalState : public MissionElement {

private:
    uav_control_states m_new_state;
    
public:
    void perform();
    void receiveMsgData(DataMsg*);

    ChangeInternalState(uav_control_states);
    ~ChangeInternalState();
};