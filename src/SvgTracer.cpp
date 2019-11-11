//
//  SvgTracer.cpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/10.
//

#include "SvgTracer.hpp"
#include "ofMain.h"

namespace orf2019 {

SvgTracer::SvgTracer():svg_{nullptr},trace_percentage_(0.f), is_trace_(false), speed_(0.01), type_(InternalPathTraceType::kForward){
    ofAddListener(ofEvents().update, this, &SvgTracer::update);
}
    
// setup()
//
// Set the target SVG.
void SvgTracer::setup(std::shared_ptr<ofxSVG> svg){
    svg_  = svg;
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
void SvgTracer::reset(){
    trace_percentage_ = 0.f;
    current_path_index_ = 0;
}

    
    
// setSpeed()
//
// Set how much the trace percentage increases per frame.
void SvgTracer::setSpeed(float speed){
    speed_ = speed;
}
   
// setInternalPathTraceType()
//
//
void SvgTracer::setInternalPathTraceType(SvgTracer::InternalPathTraceType type){
    type_ = type;
}
    
// update()
//
// This function is private member.
// Update trace progress and
void SvgTracer::update(ofEventArgs&){
    if(is_trace_) trace_percentage_ += speed_;
    
    // go to next path.
    if (trace_percentage_ > 1.0 && current_path_index_ != svg_->getNumPath()-1){
        trace_percentage_ = 0.0f;
        ++current_path_index_;
    }
}
 
    
// getCurrentPoint()
//
glm::vec2  SvgTracer::getCurrentPoint() const {
    auto current_path = svg_->getPathAt(current_path_index_);
    current_path.setPolyWindingMode(OF_POLY_WINDING_ODD); // Without this line, the number of outlines will be 0 ...
    
    std::vector<ofPolyline> outlines;
    std::copy(current_path.getOutline().begin(), current_path.getOutline().end(), std::back_inserter(outlines));
    ofPolyline all_vertices;
    for(const auto& outline : outlines){
        for(const auto& v : outline.getVertices()) all_vertices.addVertex(v);
    }
    
    auto pct = type_ == InternalPathTraceType::kForward ? trace_percentage_ : 1.0 - trace_percentage_;
    
    return all_vertices.getPointAtPercent(pct);
}
    
    
void SvgTracer::drawSvg() const {
    for(auto i = 0; i < current_path_index_+1; ++i){
        const auto& path = svg_->getPathAt(i);
        path.draw();
    }
}
    
}
