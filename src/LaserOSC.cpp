//
//  LaserOSC.cpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/10.
//

#include "LaserOSC.hpp"
#include "ofMain.h"

#define DEBUG

namespace orf2019 {
 
// setup()
//
// Setup osc sender with default settings.
void LaserOSC::setup() {
    sender_.setup("192.168.0.1", 10000);
}
    
void LaserOSC::setup(const std::string& host, int port){
    sender_.setup(host, port);
}
    
// setup()
//
// Setup osc sender on any port and host. 
void LaserOSC::drawPoint(float x, float y){
    ofxOscMessage m;
    m.setAddress("/point");
    m.addFloatArg(x);
    m.addFloatArg(y);
    sender_.sendMessage(m);
    
#ifdef DEBUG
    drawPointOnOFWindow(x, y);
#endif
}

    
void LaserOSC::drawLine(float x1, float y1, float x2, float y2){
    ofxOscMessage m;
    m.setAddress("/line");
    m.addFloatArg(x1);
    m.addFloatArg(y1);
    m.addFloatArg(x2);
    m.addFloatArg(y2);
    sender_.sendMessage(m);
    
#ifdef DEBUG
    drawLineOnOFWindow(x1, y1, x2, y2);
#endif
}
    
    
void LaserOSC::drawEllipse(float x, float y, float w, float h){
    ofxOscMessage m;
    m.setAddress("/circle");
    m.addFloatArg(x);
    m.addFloatArg(y);
    m.addFloatArg(w);
    m.addFloatArg(h);
    sender_.sendMessage(m);
    
#ifdef DEBUG
    drawEllipseOnOFWindow(x,y,w,h);
#endif
}
  
    
void LaserOSC::drawRect(float x, float y, float w, float h){
    ofxOscMessage m;
    m.setAddress("/rect");
    m.addFloatArg(x);
    m.addFloatArg(y);
    m.addFloatArg(w);
    m.addFloatArg(h);
    sender_.sendMessage(m);
#ifdef DEBUG
    drawRectOnOFWindow(x,y,w,h);
#endif
}
    
    
void LaserOSC::drawPointOnOFWindow(float x, float y){
    ofPushStyle();
    ofFill();
    ofDrawCircle(x, y, 10.0f);
    ofPopStyle();
}

    
void LaserOSC::drawLineOnOFWindow(float x1, float y1, float x2, float y2 ){
    ofPushStyle();
    ofDrawLine(x1, y1, x2, y2);
    ofPopStyle();
}
    
void LaserOSC::drawEllipseOnOFWindow(float x, float y, float w, float h){
    ofPushStyle();
    ofSetCircleResolution(60.0);
    ofNoFill();
    ofDrawEllipse(x, y, w, h);
    ofPopStyle();
}
    
    
void LaserOSC::drawRectOnOFWindow(float x, float y, float w, float h){
    ofPushStyle();
    ofNoFill();
    ofDrawEllipse(x, y, w, h);
    ofPopStyle();
}
    
    
}

