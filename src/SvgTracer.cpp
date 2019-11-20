//
//  SvgTracer.cpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/10.
//

#include "SvgTracer.hpp"
#include "ofMain.h"
#include "ofxSvg.h"
#include <random>

namespace orf2019 {

SvgTracer::SvgTracer():progress_(0.f), is_trace_(false), speed_(0.09), current_path_index_{0}{
    ofAddListener(ofEvents().update, this, &SvgTracer::update);
}
    
void SvgTracer::load(const std::string& path){
    ofxSVG svg;
    svg.load(path);
    std::transform(svg.getPaths().begin(), svg.getPaths().end(), std::back_inserter(paths_), [](ofPath path){
        path.setPolyWindingMode(OF_POLY_WINDING_ODD);
        path.setColor(ofColor(255,255,255));
        return path;
    });
}
    
void SvgTracer::start(){
    is_trace_ = true;
}
   
void SvgTracer::stop(){
    is_trace_ = false;
}

void SvgTracer::restart(){
    progress_ = 0.f;
    current_path_index_ = 0;
    if(!is_trace_) start();
}
    

void SvgTracer::reset(){
    progress_ = 0.f;
    current_path_index_ = 0;
    if(is_trace_) stop();
}
    

void SvgTracer::reverse(){
    std::reverse(paths_.begin(), paths_.end());
}
    
void SvgTracer::shuffle(){
    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    std::shuffle(paths_.begin(), paths_.end(), engine);
}


void SvgTracer::setSpeed(float speed){
    speed_ = speed;
}
    
void SvgTracer::translate(const glm::vec2& translation){
    translation_ = translation;
}
   

void SvgTracer::update(ofEventArgs&){
    if(is_trace_) progress_ += speed_;
    
    // go to next path.
    if (progress_ > 1.0 && current_path_index_ != paths_.size()-1){
        progress_ = 0.0f;
        ++current_path_index_;
    }else if ( is_trace_ && current_path_index_ == paths_.size()-1){
        stop();
        ofNotifyEvent(finish_event_);
    }
}
    
void SvgTracer::drawSvg() const {
    ofPushMatrix();
    ofTranslate(translation_);
    for(auto i = 0; i < current_path_index_+1; ++i){
        paths_.at(i).draw();
    }
    ofPopMatrix();
}
    
glm::vec2  SvgTracer::getTracingPoint() const {
    auto& current_path = paths_.at(current_path_index_);
    std::vector<ofPolyline> outlines;
    std::copy(current_path.getOutline().begin(), current_path.getOutline().end(), std::back_inserter(outlines));
    ofPolyline all_vertices;
    for(const auto& outline : outlines){
        all_vertices.addVertices(outline.getVertices());
    }
    return all_vertices.getPointAtPercent(progress_) + translation_;
}

    
}
