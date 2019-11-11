#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    laser.setup("127.0.0.1", 8888);
    auto svg = std::make_shared<ofxSVG>();
    svg -> load("equation.svg");
    
    using namespace orf2019;
    tracer.setup(svg);
    reverse_tracer.setup(svg);
    reverse_tracer.setInternalPathTraceType(SvgTracer::InternalPathTraceType::kReverse);
    
}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){

    std::stringstream ss;
    ss << "-----key------\n"
    << "Press [SPACE] : Start SVG tracing.\n"
    << "Press [RETURN] :  Stop SVG tracing. \n"
    << "Press [LEFT] : Reset SVG tracing. \n";
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

    auto reverse_tracer_point = reverse_tracer.getCurrentPoint();
    reverse_tracer_point += glm::vec2(20, ofGetHeight()/2.);
    laser.drawPoint(reverse_tracer_point.x, reverse_tracer_point.y);

    


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        tracer.start();
        reverse_tracer.start();
    }
    if (key == OF_KEY_RETURN){
        tracer.stop();
        reverse_tracer.stop();
    }
    
    if (key == OF_KEY_LEFT){
        tracer.reset();
        reverse_tracer.reset();
    }
}

