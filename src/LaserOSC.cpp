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
    // normalize
    float norm_x = ofMap(x, 0.f, ofGetWidth(), 0.f, 1.f);
    float norm_y = ofMap(y, 0.f, ofGetHeight(), 0.f, 1.f);
    ofxOscMessage m;
    m.setAddress("/point");
    m.addFloatArg(norm_x);
    m.addFloatArg(norm_y);
    sender_.sendMessage(m);
    
#ifdef DEBUG
    drawPointOnOFWindow(x, y);
#endif
}

    
void LaserOSC::drawLine(float x1, float y1, float x2, float y2){
    // normalize
    float norm_x1 = ofMap(x1, 0.f, ofGetWidth(), 0.f, 1.f);
    float norm_y1 = ofMap(y1, 0.f, ofGetWidth(), 0.f, 1.f);
    float norm_x2 = ofMap(x2, 0.f, ofGetHeight(), 0.f, 1.f);
    float norm_y2 = ofMap(y2, 0.f, ofGetHeight(), 0.f, 1.f);
    ofxOscMessage m;
    m.setAddress("/line");
    m.addFloatArg(norm_x1);
    m.addFloatArg(norm_y1);
    m.addFloatArg(norm_x2);
    m.addFloatArg(norm_y2);
    sender_.sendMessage(m);
    
#ifdef DEBUG
    drawLineOnOFWindow(x1, y1, x2, y2);
#endif
}
    
    
void LaserOSC::drawEllipse(float x, float y, float w, float h){
    // normalize
    float norm_x = ofMap(x, 0.f, ofGetWidth(), 0.f, 1.f);
    float norm_y = ofMap(y, 0.f, ofGetWidth(), 0.f, 1.f);
    float norm_w = ofMap(w, 0.f, ofGetHeight(), 0.f, 1.f);
    float norm_h = ofMap(h, 0.f, ofGetHeight(), 0.f, 1.f);
    ofxOscMessage m;
    m.setAddress("/circle");
    m.addFloatArg(norm_x);
    m.addFloatArg(norm_y);
    m.addFloatArg(norm_w);
    m.addFloatArg(norm_h);
    sender_.sendMessage(m);
    
#ifdef DEBUG
    drawEllipseOnOFWindow(x,y,w,h);
#endif
}
  
    
void LaserOSC::drawRect(float x, float y, float w, float h){
    // normalize
    float norm_x = ofMap(x, 0.f, ofGetWidth(), 0.f, 1.f);
    float norm_y = ofMap(y, 0.f, ofGetWidth(), 0.f, 1.f);
    float norm_w = ofMap(w, 0.f, ofGetHeight(), 0.f, 1.f);
    float norm_h = ofMap(h, 0.f, ofGetHeight(), 0.f, 1.f);
    ofxOscMessage m;
    m.setAddress("/rect");
    m.addFloatArg(norm_x);
    m.addFloatArg(norm_y);
    m.addFloatArg(norm_w);
    m.addFloatArg(norm_h);
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
    ofFill();
    ofDrawLine(x1, y1, x2, y2);
    ofPopStyle();
}
    
void LaserOSC::drawEllipseOnOFWindow(float x, float y, float w, float h){
    ofPushStyle();
    ofFill();
    ofDrawEllipse(x, y, w, h);
    ofPopStyle();
}
    
    
void LaserOSC::drawRectOnOFWindow(float x, float y, float w, float h){
    ofPushStyle();
    ofFill();
    ofDrawEllipse(x, y, w, h);
    ofPopStyle();
}
    
    
}

