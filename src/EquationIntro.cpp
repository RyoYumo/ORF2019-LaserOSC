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
    
EquationIntro::EquationIntro(): index_{0}, count_{0}{
    
}
    
void EquationIntro::setup(){
    ofxSubscribeOsc(8000, "/intro/restart", [&](ofxOscMessage& m){
        index_ = 0;
        tracers_[index_].restart();
    });
    
    ofxSubscribeOsc(8000, "/intro/next", [&](ofxOscMessage& m){
        ++index_;
        tracers_[index_].restart();
    });
    
    ofxSubscribeOsc(8000, "/intro/speed", [&](ofxOscMessage& m){
        for(auto& tracer : tracers_) tracer.setSpeed(m.getArgAsFloat(0) * 0.3 + 0.09);
    });
    
    // load svg
    tracers_.resize(kEquationNum);
    for(auto i = 0; i < kEquationNum; ++i){
        tracers_[i].load("equation/equation_" + ofToString(i) + ".svg");
    }
    
    tracers_[0].translate(glm::vec2(554.19, 503.55));
    tracers_[1].translate(glm::vec2(544.696, 503.55));
    tracers_[2].translate(glm::vec2(615.394, 454.5));
    tracers_[3].translate(glm::vec2(455.278, 494.842));
    tracers_[4].translate(glm::vec2(314.45, 503.55));
    tracers_[5].translate(glm::vec2(615.394,454.5));
    tracers_[6].translate(glm::vec2(192.546,503.55));
    tracers_[7].translate(glm::vec2(226.162,494.848));
    tracers_[8].translate(glm::vec2(615.394,454.5 ));
    tracers_[9].translate(glm::vec2(128.338, 494.7));
    tracers_[10].translate(glm::vec2(50.646,503.55));
    tracers_[11].translate(glm::vec2(615.394,454.5));
    tracers_[12].translate(glm::vec2(14.738,494.5));
    tracers_[13].translate(glm::vec2(822.489,513.542));
        
}
    
void EquationIntro::setLaser(LaserOSC* laser){
    laser_ = laser;
}
    
void EquationIntro::drawLaser(){
    laser_->drawPoint(tracers_[index_].getTracingPoint().x, tracers_[index_].getTracingPoint().y);
}
    
void EquationIntro::drawVisual(){
    tracers_[index_].drawSvg();
}
    

    
    
}
