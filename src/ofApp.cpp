#include "ofApp.h"
#include "ofxPubSubOsc.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    laser.setup();
    manager.addScene("Black", std::make_unique<Black>());
    manager.addScene("TestPattern", std::make_unique<orf2019::TestPattern>());
    manager.addScene("Photon", std::make_unique<orf2019::Photon>());
    manager.addScene("PhotonRemote", std::make_unique<orf2019::PhotonRemote>()); // from wakita
    manager.addScene("EquationIntro", std::make_unique<orf2019::EquationIntro>());
    manager.addScene("EquationShuffle", std::make_unique<orf2019::EquationShuffle>()); // from wakita
    manager.addScene("EquationOutro", std::make_unique<orf2019::EquationOutro>()); // from wakita



    manager.setup();
    manager.setLaser(&laser);
    manager.changeScene("TestPattern");
}


//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    manager.drawVisual();
    manager.drawLaser();
    laser.end();
    server.publishScreen();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '1'){
        manager.changeScene("Black");
    }
    
    if(key == '2'){
        manager.changeScene("TestPattern");
    }
    
    if(key == '3'){
        manager.changeScene("EquationIntro");
    }
    
    if(key == '4'){
        manager.changeScene("EquationShuffle");
    }
    
    if(key == '5'){
        manager.changeScene("EquationOutro");
    }
    
    if(key == '6'){
        manager.changeScene("PhotonRemote");
    }
    
    if(key == '7'){
        manager.changeScene("Photon");
    }
    
}

