//
//  EquationIntro.hpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/20.
//

#ifndef EquationIntro_hpp
#define EquationIntro_hpp

#include "LaserOSC.hpp"
#include "SceneManager.hpp"
#include "SvgTracer.hpp"
#include "ofEvents.h"

namespace orf2019 {
class EquationIntro  : public BaseScene {
public:
    EquationIntro();
    void setup() override;
    void setLaser(LaserOSC* laser) override;
    void drawLaser() override;
    void drawVisual() override;
        
private:
    LaserOSC* laser_;
    std::vector<SvgTracer> tracers_;
    static const int kEquationNum = 14;
    std::size_t index_;
    std::size_t count_;
};
}

#endif /* EquationIntro_hpp */
