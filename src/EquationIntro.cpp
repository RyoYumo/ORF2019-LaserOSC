//
//  EquationIntro.cpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/20.
//

#include "EquationIntro.hpp"
#include "ofxPubSubOsc.h"
#include "ofMain.h"

namespace orf2019 {
    
EquationIntro::EquationIntro(): index_{0}, speed_(0.09),is_finish_event_{false}, delay_timer_{0.0}{}
    
void EquationIntro::setup(){
    // load svg
    tracers_.resize(kEquationNum);
    for(auto i = 0; i < kEquationNum; ++i){ tracers_[i].load("equation/equation_" + ofToString(i) + ".svg"); }

    // translation setting
    ofJson js = ofLoadJson("equation/translation.json");
    for(auto i = 0; i < js.size(); ++i){ tracers_[i].translate(glm::vec2{js[ofToString(i)]["x"], js[ofToString(i)]["y"]}); }
    
    ofAddListener(ofEvents().update, this, &EquationIntro::update);
    
    //init
    for(auto& tracer : tracers_){
        ofAddListener(tracer.getFinishEvent(), this, &EquationIntro::nextEquation);
        tracer.setSpeed(speed_);
    }
    
    tracers_[index_].start();
}

void EquationIntro::reset(){
    is_finish_event_ = false;
    speed_ = 0.09;
    index_ = 0;
    delay_timer_ = 0.0;
    tracers_[index_].restart();
}
    
void EquationIntro::nextEquation(){
    is_finish_event_ = true;
}
    
void EquationIntro::setLaser(LaserOSC* laser){
    laser_ = laser;
}
    
void EquationIntro::update(ofEventArgs&){
    if(is_finish_event_){ delay_timer_ += 0.05;}
    if(delay_timer_ > 1) {
        is_finish_event_ = false;
        delay_timer_ = 0.0;
        if(index_ < kEquationNum-1) {
            ++index_;
            speed_ += 0.025;
            tracers_[index_].restart();
            tracers_[index_].setSpeed(speed_);
        }
    }
    
}
    
void EquationIntro::drawLaser(){
    laser_->drawPoint(tracers_[index_].getTracingPoint().x, tracers_[index_].getTracingPoint().y);
}
    
void EquationIntro::drawVisual(){
    tracers_[index_].drawSvg();
}
}
