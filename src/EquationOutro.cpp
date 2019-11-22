//
//  EquationOutro.cpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/21.
//

#include "EquationOutro.hpp"
#include "ofxPubSubOsc.h"
#include "ofMain.h"

namespace orf2019 {
EquationOutro::EquationOutro(){}
    
void EquationOutro::setup(){
    ofxSubscribeOsc(8000, "/outro/restart", [&](ofxOscMessage& m){ tracer_.restart();});
    tracer_.load("equation/equation_" + ofToString(12) + ".svg");
    tracer_.setSpeed(0.2);
    tracer_.translate(glm::vec2(14.738,494.5));
}
    
void EquationOutro::setLaser(LaserOSC* laser){
    laser_ = laser;
}
    
void EquationOutro::reset(){
    tracer_.restart();
}
    
void EquationOutro::drawLaser(){
    laser_->drawPoint(tracer_.getTracingPoint().x, tracer_.getTracingPoint().y);
}
    
void EquationOutro::drawVisual(){
    tracer_.drawSvg();
}
    
    
    
    
}
