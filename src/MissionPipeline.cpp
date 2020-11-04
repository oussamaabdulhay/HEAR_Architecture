#include "HEAR_mission/MissionPipeline.hpp"

MissionPipeline::MissionPipeline() {

}

MissionPipeline::~MissionPipeline() {

}

void MissionPipeline::addElement(MissionElement* t_element){
    _list_of_elements.push_back(t_element);
}

void MissionPipeline::execute(){
    std::list<MissionElement*>::iterator it;
    for (it = _list_of_elements.begin(); it != _list_of_elements.end(); ++it){
        (*it)->perform();
    }
}