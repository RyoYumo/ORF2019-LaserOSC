//
//  RadicalMask.hpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/15.
//

#ifndef RadicalMask_hpp
#define RadicalMask_hpp
#include "ofShader.h"
#include "glm/glm.hpp"

namespace orf2019 {
// simple shader wrapper
class RadicalMask {
public:
    RadicalMask();
    void begin();
    void end();
    void setRadius(float radius) { radius_ = radius;}
    void setCenter(const glm::vec2& center) { center_ = center; }
    void setOpacity(float opacity) { opacity_ = opacity; }
    
private:
    ofShader shader_;
    float radius_;
    glm::vec2 center_;
    float opacity_;
        
};
}

#endif /* RadicalMask_hpp */
