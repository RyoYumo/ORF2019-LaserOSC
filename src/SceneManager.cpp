//
//  SceneManager.cpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/19.
//

#include "SceneManager.hpp"
namespace orf2019 {
    
SceneManager::SceneManager(): current_scene_name_(){
        
}
    
void SceneManager::addScene(const std::string& scene_name, std::shared_ptr<BaseScene> scene){
    scenes_.insert(std::make_pair(scene_name, scene));
}
    
void SceneManager::setup(){
    current_scene_name_ = scenes_.begin()->first;
    for(auto scene : scenes_) scene.second->setup();
}
    
void SceneManager::setLaser(LaserOSC* laser){
    for(auto scene : scenes_) scene.second->setLaser(laser);
}

    
void SceneManager::drawLaser(){
    scenes_[current_scene_name_]->drawLaser();
}
    
void SceneManager::drawVisual(){
    scenes_[current_scene_name_]->drawVisual();
}
    
std::shared_ptr<BaseScene> SceneManager::getScene(const std::string& name) {
    decltype(scenes_)::iterator itr = scenes_.find(name);
    if(itr!=scenes_.end()){
        return itr->second;
    }else{
        return nullptr;
    }
}
    
void SceneManager::changeScene(const std::string& name){
    decltype(scenes_)::iterator itr = scenes_.find(name);
    if(itr!=scenes_.end()){
        current_scene_name_ = name;
    }
}


    
    
}
