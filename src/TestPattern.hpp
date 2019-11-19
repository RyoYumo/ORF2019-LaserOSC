//
//  TestPattern.hpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/19.
//

#ifndef TestPattern_hpp
#define TestPattern_hpp

#include "LaserOSC.hpp"
#include "SceneManager.hpp"
#include "ofMain.h"

namespace orf2019 {
class TestPattern : public BaseScene {
public:
    void setup() override {}
    void setLaser(LaserOSC* laser) override { laser_ = laser; }
    void drawLaser() override {}
    void drawVisual() override {
        float radius = 30.0f;
        ofPushStyle();
        ofNoFill();
        ofSetColor(255,0,0);
        ofSetLineWidth(3.0);
        ofPushMatrix();
        ofTranslate(100, 100);
        ofDrawCircle(0, 0, radius);
        ofDrawLine(glm::vec2(radius * cos(HALF_PI), radius * sin(HALF_PI)), glm::vec2(radius * cos(-HALF_PI), radius * sin(-HALF_PI)));
        ofDrawLine(glm::vec2(radius * cos(0), radius * sin(0)), glm::vec2(radius * cos(PI), radius * sin(PI)));
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(1820, 100);
        ofDrawCircle(0, 0, radius);
        ofDrawLine(glm::vec2(radius * cos(HALF_PI), radius * sin(HALF_PI)), glm::vec2(radius * cos(-HALF_PI), radius * sin(-HALF_PI)));
        ofDrawLine(glm::vec2(radius * cos(0), radius * sin(0)), glm::vec2(radius * cos(PI), radius * sin(PI)));
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(100, 980);
        ofDrawCircle(0, 0, radius);
        ofDrawLine(glm::vec2(radius * cos(HALF_PI), radius * sin(HALF_PI)), glm::vec2(radius * cos(-HALF_PI), radius * sin(-HALF_PI)));
        ofDrawLine(glm::vec2(radius * cos(0), radius * sin(0)), glm::vec2(radius * cos(PI), radius * sin(PI)));
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(1820, 980);
        ofDrawCircle(0, 0, radius);
        ofDrawLine(glm::vec2(radius * cos(HALF_PI), radius * sin(HALF_PI)), glm::vec2(radius * cos(-HALF_PI), radius * sin(-HALF_PI)));
        ofDrawLine(glm::vec2(radius * cos(0), radius * sin(0)), glm::vec2(radius * cos(PI), radius * sin(PI)));
        ofPopMatrix();
        ofPopStyle();
    }
    
private:
    LaserOSC* laser_;
};
    
}



#endif /* TestPattern_hpp */
