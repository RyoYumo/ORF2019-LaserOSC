//
//  PhotonRemote.hpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/21.
//

#ifndef PhotonRemote_hpp
#define PhotonRemote_hpp

#include "LaserOSC.hpp"
#include "SceneManager.hpp"
#include "glm/glm.hpp"
#include "ofImage.h"
#include <vector>

namespace orf2019 {
class PhotonRemote : public BaseScene{
public:
    PhotonRemote():index_{0}, data_(kImageNum){}
    void setLaser(LaserOSC* laser) override { laser_ = laser; }
    void setup() override;
    void reset() override {}
    void drawLaser() override;
    void drawVisual() override;
private:
    void drawTracingPoint();
    void drawOutlineCircle();
    static const int kImageNum = 136;
    struct CircleData { float x, y, radius; };
    struct Data {
        std::vector<CircleData> circles;
    };
    std::vector<Data> data_;
    LaserOSC* laser_;
    std::size_t index_;
};
}

#endif /* PhotonRemote_hpp */
