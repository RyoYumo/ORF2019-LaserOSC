//
//  SvgTracer.cpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/10.
//

#include "SvgTracer.hpp"
#include "ofMain.h"

namespace orf2019 {

SvgTracer::SvgTracer():svg_{nullptr},trace_percentage_(0.f), is_trace(false), speed_(0.01){
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
    is_trace = true;
}
   
// stop()
//
// Stop tracing.
void SvgTracer::stop(){
    is_trace = false;
}

// reset()
//
// From the beginning
void SvgTracer::reset(){
    trace_percentage_ = 0.f;
    current_path_index = 0;
}
    
    
// setSpeed()
//
// Set how much the trace percentage increases per frame.
void SvgTracer::setSpeed(float speed){
    speed_ = speed;
}
    
    
// update()
//
// This function is private member.
// Update trace progress and
void SvgTracer::update(ofEventArgs&){
    if(is_trace) trace_percentage_ += speed_;
    
    // go to next path.
    if (trace_percentage_ > 1.0 && current_path_index != svg_->getNumPath()-1){
        trace_percentage_ = 0.0f;
        ++current_path_index;
    }
}
 
    
// getCurrentPoint()
//
glm::vec2  SvgTracer::getCurrentPoint() const {
    auto current_path = svg_->getPathAt(current_path_index);
    current_path.setPolyWindingMode(OF_POLY_WINDING_ODD); // Without this line, the number of outlines will be 0 ...
    
    std::vector<ofPolyline> outlines;
    std::copy(current_path.getOutline().begin(), current_path.getOutline().end(), std::back_inserter(outlines));
    ofPolyline all_vertices;
    for(const auto& outline : outlines){
        for(const auto& v : outline.getVertices()) all_vertices.addVertex(v);
    }
    return all_vertices.getPointAtPercent(trace_percentage_);
}

    
    
}
