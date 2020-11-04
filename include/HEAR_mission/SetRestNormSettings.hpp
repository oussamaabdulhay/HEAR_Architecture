#pragma once

#include "HEAR_mission/MissionElement.hpp"
#include "HEAR_msg/RestrictedNormRefSettingsMsg.hpp"

class SetRestNormSettings : public MissionElement {
private:
    Port* _output_port_0;
	bool _enabled, _delete;
    float _max_norm;
public:
    enum ports_id {OP_0};
    RestrictedNormRefSettingsMsg _settings_msg;
    void perform();
    void process(DataMsg* t_msg, Port* t_port) {};
    SetRestNormSettings(bool, bool, float);
    ~SetRestNormSettings();
};