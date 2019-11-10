#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    laser.setup();
    auto svg = std::make_shared<ofxSVG>();
    svg -> load("equation.svg");
    tracer.setup(svg);
}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){
    laser.drawPoint(ofGetWidth()/2, ofGetHeight()/2.);
    laser.drawLine(0, 0,ofGetWidth(), ofGetHeight());
    
    ofPushMatrix();
    ofTranslate(20, ofGetHeight()/2.);
    tracer.getSvg()->draw();
    ofPopMatrix();
    
    auto tracer_point = tracer.getCurrentPoint();
    tracer_point += glm::vec2(20, ofGetHeight()/2.);
    laser.drawPoint(tracer_point.x, tracer_point.y);

    


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        tracer.start();
    }
    if (key == '1'){
        tracer.stop();
    }
}

