//
//  Photon.hpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/19.
//

#ifndef Photon_hpp
#define Photon_hpp

#include "LaserOSC.hpp"
#include "SceneManager.hpp"
#include "glm/glm.hpp"
#include "ofImage.h"
#include <unordered_map>

namespace orf2019 {
class Photon : public BaseScene{
public:
    Photon():index_{0}, data_(kImageNum), state_{DrawState::kOutline}{}
    void setLaser(LaserOSC* laser) override { laser_ = laser; }
    void setup() override;
    void drawLaser() override;
    void drawVisual() override;
    void drawTracingPoint();
    void drawOutlineCircle();
    
private:
    enum class DrawState { kOutline, kTracing };
    static const int kImageNum = 136;
    struct CircleData { float x, y, radius; };
    struct Data {
        ofImage img;
        std::vector<CircleData> circles;
    };
    std::vector<Data> data_;
    LaserOSC* laser_;
    std::size_t index_;
    float degree_;
    DrawState state_;

};
}

#endif /* Photon_hpp */
