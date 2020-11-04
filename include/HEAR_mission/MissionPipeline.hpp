#pragma once
#include <list>
#include "HEAR_mission/MissionElement.hpp"

class MissionPipeline {
private:
    std::list<MissionElement*> _list_of_elements;
public:
    void addElement(MissionElement*);
    void execute();
    MissionPipeline();
    ~MissionPipeline();
};