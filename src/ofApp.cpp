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

    std::stringstream ss;
    ss << "-----key------\n"
    << "Press [SPACE] : SVG trace start.\n"
    << "Press [RETURN] :  SVG trace top. \n";
    ofPushStyle();
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(ss.str(), 20, 20);
    ofPopStyle();
    
    
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
    if (key == OF_KEY_RETURN){
        tracer.stop();
    }
    
    if (key == OF_KEY_LEFT){
        tracer.reset();
    }
}
