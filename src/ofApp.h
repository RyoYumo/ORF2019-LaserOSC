#pragma once

#include "ofMain.h"
#include "LaserOSC.hpp"
#include "ofxSvg.h"
#include "SvgTracer.hpp"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
private:
    orf2019::LaserOSC  laser;
    orf2019::SvgTracer tracer;
};
