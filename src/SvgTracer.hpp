//
//  SvgTracer.hpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/10.
//

#ifndef SvgTracer_hpp
#define SvgTracer_hpp

#include "ofPath.h"
#include "LaserOSC.hpp"
#include <memory>
#include <vector>

namespace orf2019 {
class SvgTracer {
public:
    SvgTracer();
    void          load(const std::string& path);
    void          start();
    void          stop();
    void          restart();
    void          reverse();
    void          setSpeed(float speed);
    void          translate(const glm::vec2& translation);
    void          drawSvg() const ;
    glm::vec2     getTracingPoint() const;
    ofEvent<int>& getFinishEvent() { return finish_event_;}
    
private:
    std::vector<ofPath> paths_;
    float               progress_;
    float               speed_;
    bool                is_trace_;
    int                 current_path_index_;
    void                update(ofEventArgs&);
    glm::vec2           translation_;
    ofEvent<int>        finish_event_;
};
} // namespace orf2019




#endif /* SvgTracer_hpp */
