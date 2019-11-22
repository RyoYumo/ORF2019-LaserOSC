//
//  PhotonRemoteRemoteRemote.cpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/21.
//

#include "PhotonRemote.hpp"
#include "ofMain.h"
#include "ofxPubSubOsc.h"

namespace orf2019 {
void PhotonRemote::setup(){
    // OSC
    const int kPort = 2346;
    ofxSubscribeOsc(kPort, "/photon/number", index_);
    // load coord info
    ofJson js = ofLoadJson("Photon/photon.json");
    for(auto i = 0; i < kImageNum; ++i){
        auto d = js[ofToString(i)];
        for(auto&& dd : d){
            CircleData data;
            data.x = dd["x"]; data.y = dd["y"]; data.radius = dd["radius"];
            data_[i].circles.push_back(data);
        }
    }
}
    
void PhotonRemote::drawVisual(){
        
}
    
    
void PhotonRemote::drawLaser(){
    drawOutlineCircle();
    drawTracingPoint();
}
    
void PhotonRemote::drawOutlineCircle(){
    for(const auto& d : data_[index_].circles){
        laser_->drawEllipse(d.x, d.y, d.radius*2.0, d.radius*2.0);
    }
}
    
    
void PhotonRemote::drawTracingPoint(){
    auto first = data_[index_].circles.begin();
    auto last  = data_[index_].circles.end();
    for(; first != last; ++first){
        laser_->drawPoint(first->x + first->radius * cos(ofGetElapsedTimef()), first-> y + first->radius * sin(ofGetElapsedTimef()));
        laser_->drawPoint(first->x + first->radius * cos(-1 * ofGetElapsedTimef()), first-> y + first->radius * sin(-1 * ofGetElapsedTimef()));
    }
}
}
