//
//  RadicalMask.cpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/15.
//

#include "RadicalMask.hpp"

namespace orf2019 {

RadicalMask::RadicalMask(): radius_(200.0f),center_{0,0}{
    shader_.load("shader/radical_mask.vert", "shader/radical_mask.frag");
}
    
void RadicalMask::begin(){
    shader_.begin();
    shader_.setUniform1f("u_radius", radius_);
    shader_.setUniform2f("u_center", center_);
    shader_.setUniform1f("u_opacity", 0.5);

}
    
void RadicalMask::end(){
    shader_.end();
}
    

    
    
}
