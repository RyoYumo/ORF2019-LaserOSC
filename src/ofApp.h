#pragma once

#include "ofMain.h"
#include "LaserOSC.hpp"
#include "SvgTracer.hpp"
#include "RadicalMask.hpp"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void drawTestPattern();
    void finishCallback(int& n){
        // 10 loop 
        if (n < 10) tracer.restart();
    }
    
    
private:
    orf2019::LaserOSC  laser;
    orf2019::SvgTracer tracer;
    orf2019::SvgTracer reverse_tracer;
    orf2019::RadicalMask radical_mask;
    ofPolyline poly;
    bool is_draw = false;
    bool is_test = false;
    glm::vec2 svg_pos;
    float speed = 0.06;
    int index = 0;
};
