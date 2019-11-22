//
//  EquationOutro.hpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/21.
//

#ifndef EquationOutro_hpp
#define EquationOutro_hpp

#include "LaserOSC.hpp"
#include "SceneManager.hpp"
#include "SvgTracer.hpp"
#include "ofEvents.h"

namespace orf2019 {
class EquationOutro  : public BaseScene {
public:
    EquationOutro();
    void setup() override;
    void setLaser(LaserOSC* laser) override;
    void drawLaser() override;
    void drawVisual() override;
    void reset() override;
        
private:
    LaserOSC* laser_;
    SvgTracer tracer_;
};
}

#endif /* EquationOutro_hpp */
