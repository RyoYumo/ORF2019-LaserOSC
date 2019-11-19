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
#include <unordered_map>

namespace orf2019 {
class Photon : public BaseScene{
public:
    Photon():index_{0}{}
    void setLaser(LaserOSC* laser) override { laser_ = laser; }
    void setup() override;
    void drawLaser() override;
    void drawVisual() override {}
    
private:
    struct Data { float x, y, radius; };
    std::map<int, std::vector<Data>> img_data_map_;
    LaserOSC* laser_;
    std::size_t index_;

};
}

#endif /* Photon_hpp */
