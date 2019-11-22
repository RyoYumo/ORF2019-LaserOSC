//
//  LaserOSC.hpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/10.
//

#ifndef LaserOSC_hpp
#define LaserOSC_hpp

#include "ofxOsc.h"

namespace orf2019 {
class LaserOSC {
public:
    void setup();
    void setup(const std::string& host, int port);
    void drawPoint(float x, float y);
    void drawLine(float x1, float y1, float x2, float y2);
    void drawEllipse(float x, float y, float w, float h);
    void drawRect(float x, float y, float w, float h);
    void end();
private:
    void drawPointOnOFWindow(float x, float y);
    void drawLineOnOFWindow(float x1, float y1, float x2, float y2);
    void drawEllipseOnOFWindow(float x, float y, float w, float h);
    void drawRectOnOFWindow(float x, float y, float w, float h);
    ofxOscSender sender_;
};
} // namespace ofr2019




#endif /* LaserOSC_hpp */
