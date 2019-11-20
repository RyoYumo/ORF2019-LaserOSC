//
//  EquationShuffle.cpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/20.
//

#include "EquationShuffle.hpp"
#include "ofxPubSubOsc.h"

namespace orf2019 {
void EquationShuffle::setup(){
    ofxSubscribeOsc(8000, "/shuffle/restart", [&](ofxOscMessage& m){
        for(auto& tracer : tracers_) {
            tracer.restart();
            tracer.shuffle();
        }
    });
    
    for(auto i = 0; i < kEquationNum; ++i){
        tracers_[i].load("equation/equation_12.svg");
    }
    for(auto i = 0; i < kEquationNum; ++i){
        tracers_[i].setSpeed(0.1);
        tracers_[i].shuffle();
        tracers_[i].translate(glm::vec2(14.738, i * 200));
    }
}
    
void EquationShuffle::setLaser(LaserOSC* laser){
    laser_ = laser;
}

    
void EquationShuffle::drawLaser(){
    for(auto i = 0; i < tracers_.size(); ++i){
        laser_->drawPoint(tracers_[i].getTracingPoint().x, tracers_[i].getTracingPoint().y);
    }
}
    
void EquationShuffle::drawVisual(){
    for(auto i = 0; i < tracers_.size(); ++i){
        tracers_[i].drawSvg();
    }
}
}
