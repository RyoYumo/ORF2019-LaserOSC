//
//  Photon.cpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/19.
//

#include "Photon.hpp"
#include "ofMain.h"
#include "ofxPubSubOsc.h"

namespace orf2019 {
void Photon::setup(){
    // OSC
    const int kPort = 8000;
    ofxSubscribeOsc(kPort, "/photon/next", [&](){ index_ = ofRandom(0, 136);}); // random index
    ofxSubscribeOsc(kPort, "/photon/degree", [&](ofxOscMessage& m) { degree_ = m.getArgAsFloat(0) * 360 - 90.0;}); // for tracing
    ofxSubscribeOsc(kPort, "/photon/outline", [&](ofxOscMessage& m){ state_ = DrawState::kOutline;}); // change draw state
    ofxSubscribeOsc(kPort, "/photon/tracing", [&](ofxOscMessage& m){ state_ = DrawState::kTracing;}); // change draw state
    
    // load img
    for(auto i = 0; i < kImageNum; ++i){
        data_[i].img.load("photon/images/" + ofToString(i) + ".png");
    }
    
    // load coord info
    ofJson js = ofLoadJson("photon/photon.json");
    for(auto i = 0; i < kImageNum; ++i){
        auto d = js[ofToString(i)];
        for(auto&& dd : d){
            CircleData data;
            data.x = dd["x"]; data.y = dd["y"]; data.radius = dd["radius"];
            data_[i].circles.push_back(data);
        }
    }
}
    
void Photon::drawVisual(){
    data_[index_].img.draw(1920. * 0.5 - 1080. * 0.5, 0, 1080.,1080.);
}
    
void Photon::drawLaser(){
    if (state_ == DrawState::kOutline) drawOutlineCircle(); else drawTracingPoint();
}
    
void Photon::drawOutlineCircle(){
    for(const auto& d : data_[index_].circles){
        ofPushMatrix();
        ofTranslate(d.x, d.y);
        laser_->drawEllipse(0, 0, d.radius*2.0, d.radius*2.0);
        ofPopMatrix();
    }
}
    
    
void Photon::drawTracingPoint(){
    for(const auto& d : data_[index_].circles){
        ofPushMatrix();
        ofTranslate(d.x, d.y);
        laser_->drawPoint(d.radius * cos(ofDegToRad(degree_)), d.radius * sin(ofDegToRad(degree_)));
        laser_->drawPoint(d.radius * cos(ofDegToRad(-1 * degree_)), d.radius * sin(ofDegToRad(-1 * degree_)));
        ofPopMatrix();
    }
}
}
