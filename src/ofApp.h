#pragma once

#include "ofMain.h"
#include "LaserOSC.hpp"
#include "TestPattern.hpp"
#include "SceneManager.hpp"
#include "Photon.hpp"
#include "EquationShuffle.hpp"
#include "EquationIntro.hpp"
#include "EquationOutro.hpp"
#include "PhotonRemote.hpp"
#include "ofxSyphon.h"

class Black : public orf2019::BaseScene {
public:
    void setup() override {}
    void setLaser(orf2019::LaserOSC* laser) override {}
    void reset() override {}
    void drawLaser() override{}
    void drawVisual() override { ofBackground(0,0,0); }
};

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
private:
    orf2019::LaserOSC     laser;
    orf2019::SceneManager manager;
    ofxSyphonServer       server;
};
