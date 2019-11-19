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
    ofxSubscribeOsc(54321, "/img", index_);
    
    ofJson js;
    js = ofLoadJson("photon/photon-1.json");
    for(auto i = 0; i < js.size(); ++i){
        auto d = js[ofToString(i)];
        for(auto dd : d){
            Data data;
            data.x = dd["x"];
            data.y = dd["y"];
            data.radius = dd["radius"];
            img_data_map_[i].push_back(data);
        }
    }
}
    
void Photon::drawLaser(){
    auto data = img_data_map_[index_];
    for(auto d : data){
        laser_->drawEllipse(d.x, d.y, d.radius, d.radius);
    }
}
    
    
}
