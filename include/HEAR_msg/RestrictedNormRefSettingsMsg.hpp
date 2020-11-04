#pragma once

#include "HEAR_core/DataMsg.hpp"

class RestrictedNormRefSettingsMsg : public DataMsg {
public:
    float max_norm = 0.2;
    bool enabled=true;//Disabling stops updating reference value
    bool delete_existing_waypoints=false;//Setting to true clears all uploaded waypoints. No retention.
    msg_type getType() {return msg_type::RESTNORMREF_SETTINGS;};
    const int getSize() {return sizeof(RestrictedNormRefSettingsMsg);};
};