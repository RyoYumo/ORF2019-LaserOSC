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
    drawOutlineCircle();
    drawTracingPoint();
}
    
void Photon::drawOutlineCircle(){
    for(const auto& d : data_[index_].circles){
        laser_->drawEllipse(d.x, d.y, d.radius*2.0, d.radius*2.0);
    }
}
    
    
void Photon::drawTracingPoint(){
    auto first = data_[index_].circles.begin();
    auto last  = data_[index_].circles.end();
    for(; first != last; ++first){
        auto offset = std::distance(data_[index_].circles.begin(), first) % 2 == 0 ? HALF_PI : 0;
        laser_->drawPoint(first->x + first->radius * cos(ofGetElapsedTimef() + offset), first->y +first->radius * sin(ofGetElapsedTimef() + offset));
        laser_->drawPoint(first-> x + first->radius * cos(-1 * ofGetElapsedTimef() + offset), first->y + first->radius * sin(-1 * ofGetElapsedTimef() + offset));
     
    }
}
    
    
void Photon::update(ofEventArgs&){
    progress_+=speed_;
    if(progress_ > 1.0) {
        index_ = ofRandom(0, 136);
        progress_ = 0.0;
    }
}

void Photon::reset(){
    progress_ = 0.0;
}
    
}
