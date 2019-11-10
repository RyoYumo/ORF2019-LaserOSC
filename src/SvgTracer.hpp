//
//  SvgTracer.hpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/10.
//

#ifndef SvgTracer_hpp
#define SvgTracer_hpp

#include "ofxSvg.h"
#include "ofPolyline.h"
#include <memory>

namespace orf2019 {
class SvgTracer {
public:
    SvgTracer();
    void       setup(std::shared_ptr<ofxSVG> svg);
    void       start();
    void       stop();
    void       reset();
    void       setSpeed(float speed);
    glm::vec2  getCurrentPoint() const ;
    std::shared_ptr<ofxSVG> getSvg() { return svg_;}
    
private:
    void update(ofEventArgs&);
    std::shared_ptr<ofxSVG> svg_;
    float trace_percentage_;
    float speed_;
    bool  is_trace;
    int   current_path_index;
};
} // namespace orf2019




#endif /* SvgTracer_hpp */
