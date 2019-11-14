//
//  SvgTracer.cpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/10.
//

#include "SvgTracer.hpp"
#include "ofMain.h"
#include "ofxSvg.h"

namespace orf2019 {

SvgTracer::SvgTracer():output_{nullptr}, progress_(0.f), is_trace_(false), speed_(0.01), current_path_index_{0}{
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
    
    
void SvgTracer::setLaserOutput(LaserOSC* output){
    output_ = output;
}

    

// start()
//
// Start tracing.
void SvgTracer::start(){
    is_trace_ = true;
}
   
// stop()
//
// Stop tracing.
void SvgTracer::stop(){
    is_trace_ = false;
}

// reset()
//
// From the beginning
void SvgTracer::restart(){
    progress_ = 0.f;
    current_path_index_ = 0;
    if(!is_trace_) start();
}
    

void SvgTracer::reverse(){
    std::reverse(paths_.begin(), paths_.end());
}
    
    
// setSpeed()
//
// Set how much the trace percentage increases per frame.
void SvgTracer::setSpeed(float speed){
    speed_ = speed;
}
    
void SvgTracer::translate(const glm::vec2& translation){
    translation_ = translation;
}
   
// update()
//
// This function is private member.
// Update trace progress and
void SvgTracer::update(ofEventArgs&){
    if(is_trace_) progress_ += speed_;
    
    // go to next path.
    if (progress_ > 1.0 && current_path_index_ != paths_.size()-1){
        progress_ = 0.0f;
        ++current_path_index_;
    }else if ( is_trace_ && current_path_index_ == paths_.size()-1){
        stop();
        static int n = 0;
        ++n;
        ofNotifyEvent(finish_event_, n);
    }
}
    
void SvgTracer::drawSvg() const {
    ofPushMatrix();
    ofTranslate(translation_);
    for(auto i = 0; i < current_path_index_+1; ++i){
        auto& path = paths_.at(i);
        path.draw();
    }
    ofPopMatrix();
}
    
void SvgTracer::drawPointOnTracing() const{
    if(output_){ // nullptr check
        auto current_path = paths_.at(current_path_index_);
        std::vector<ofPolyline> outlines;
        std::copy(current_path.getOutline().begin(), current_path.getOutline().end(), std::back_inserter(outlines));
        ofPolyline all_vertices;
        for(const auto& outline : outlines){
            for(const auto& v : outline.getVertices()) all_vertices.addVertex(v);
        }
        
        auto pct = progress_;
        auto point = all_vertices.getPointAtPercent(pct) + translation_;
        output_-> drawPoint(point.x, point.y);
        
    }else{
        ofLogError() << "Not found laser output. Please call setLayserOutput()...";
    }
}
    
    
glm::vec2  SvgTracer::getPointOnTracing() const{
    auto current_path = paths_.at(current_path_index_);
    std::vector<ofPolyline> outlines;
    std::copy(current_path.getOutline().begin(), current_path.getOutline().end(), std::back_inserter(outlines));
    ofPolyline all_vertices;
    for(const auto& outline : outlines){
        for(const auto& v : outline.getVertices()) all_vertices.addVertex(v);
    }
    
    auto pct = progress_;
    auto point = all_vertices.getPointAtPercent(pct) + translation_;
    return point;
}

    
}
