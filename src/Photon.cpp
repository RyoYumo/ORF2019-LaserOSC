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
    ofxSubscribeOsc(8000, "/img", [&](){ index_ = ofRandom(0, 136);});
    ofJson js;
    js = ofLoadJson("photon/photon-1.json");
    const int kImageNum = 136;
    data_.resize(kImageNum);
    
    for(auto i = 0; i < kImageNum; ++i){
        data_[i].img.load("photon/images/" + ofToString(i) + ".png");
    }
    
    for(auto i = 0; i < kImageNum; ++i){
        auto d = js[ofToString(i)];
        for(auto dd : d){
            CircleData data;
            data.x = dd["x"];
            data.y = dd["y"];
            data.radius = dd["radius"];
            data_[i].circles.push_back(data);
        }
    }
}
    
void Photon::drawVisual(){
    data_[index_].img.draw(1920. * 0.5 - 1080. * 0.5, 0, 1080.,1080.);
}
    
void Photon::drawLaser(){
    for(auto d : data_[index_].circles){
        ofPushMatrix();
        ofTranslate(d.x, d.y);
        laser_->drawEllipse(0, 0, d.radius*2.0, d.radius*2.0);
        ofPopMatrix();
    }
}
    
}
