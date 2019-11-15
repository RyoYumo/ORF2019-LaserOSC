#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    
    /* setup laser OSC output
     laser.setup(); -> connect HOST "192.168.0.1" PORT 10000 */
    laser.setup("127.0.0.1", 8989);
    
    // load svg
    tracer.load("original/equation_2.svg");
    
    // set trace speed
    tracer.setSpeed(0.09);
    
    // svg translation pos
    tracer.translate(glm::vec2(100, ofGetHeight()/2.));
    
    
    for(auto i = 0; i < 100; ++i){
        poly.addVertex(glm::vec3(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0));
    }
    
    // add trace finish callback
    ofAddListener(tracer.getFinishEvent(), this, &ofApp::finishCallback);
    
    radical_mask.setOpacity(0.5);
    radical_mask.setRadius(200.0f);
    
}


//--------------------------------------------------------------
void ofApp::update(){
    radical_mask.setCenter(tracer.getTracingPoint());
}


// laser calibration test pattern
void ofApp::drawTestPattern(){
    // laser coord
    laser.drawPoint(ofGetWidth()/2, ofGetHeight()/2.);
    laser.drawPoint(0, ofGetHeight()/2.);
    laser.drawPoint(ofGetWidth(), ofGetHeight()/2.);
    laser.drawPoint(ofGetWidth()/2., 0);
    laser.drawPoint(ofGetWidth()/2., ofGetHeight());
    
    
    
    // pixel coord
    ofPushStyle();
    ofSetColor(255,255,255);
    ofDrawCircle(ofGetWidth()/2., ofGetHeight()/2., 20);
    ofDrawCircle(0., ofGetHeight()/2., 20);
    ofDrawCircle(ofGetWidth(), ofGetHeight()/2., 20);
    ofDrawCircle(ofGetWidth()/2., 0, 20);
    ofDrawCircle(ofGetWidth()/2., ofGetHeight(), 20);
    ofPopStyle();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (is_test) drawTestPattern();
    
    if (is_draw){
        ofPushMatrix();
        ofSetColor(255, 255, 255);
        tracer.drawSvg();
        ofPopMatrix();
        laser.drawPoint(tracer.getTracingPoint().x, tracer.getTracingPoint().y);

        // mask effect
        radical_mask.begin();
        poly.draw();
        radical_mask.end();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        tracer.start();
        is_draw = true;
    }
    
    if (key == OF_KEY_RETURN){
        tracer.stop();
        is_draw = false;
    }
    
    if (key == OF_KEY_LEFT){
        tracer.restart();
    }
    
    if (key == 'd'){
        is_test = !is_test;
    }
}

