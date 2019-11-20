//
//  EquationShuffle.hpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/20.
//

#ifndef EquationShuffle_hpp
#define EquationShuffle_hpp

#include "LaserOSC.hpp"
#include "SceneManager.hpp"
#include "SvgTracer.hpp"
#include "ofEvents.h"

namespace orf2019 {
class EquationShuffle  : public BaseScene {
public:
    EquationShuffle():tracers_{kEquationNum}{}
    void setup() override;
    void setLaser(LaserOSC* laser) override;
    void drawLaser() override;
    void drawVisual() override;
    
private:
    LaserOSC* laser_;
    std::vector<SvgTracer> tracers_;
    static const int kEquationNum = 6;
    std::size_t index_ {0};
    std::size_t count_ {0};
};
}

#endif /* EquationShuffle_hpp */
