//
//  SceneManager.hpp
//  ORF2019-LaserOSC
//
//  Created by Ryo Yumoto on 2019/11/19.
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include "LaserOSC.hpp"
#include <map>
#include <memory>
#include <string>

namespace orf2019 {
class BaseScene {
public:
    virtual ~BaseScene() = default;
    virtual void setup() = 0;
    virtual void setLaser(LaserOSC* laser) = 0;
    virtual void drawLaser() = 0;
    virtual void drawVisual() = 0;
};
    
    
class SceneManager {
public:
    SceneManager();
    void addScene(const std::string& scene_name, std::shared_ptr<BaseScene> scene);
    void setup();
    void setLaser(LaserOSC* laser);
    void drawLaser();
    void drawVisual();
    std::shared_ptr<BaseScene> getScene(const std::string& name);
    void changeScene(const std::string& name);
private:
    std::map<std::string, std::shared_ptr<BaseScene>> scenes_;
    std::string current_scene_name_;
        
};
    
    
}


#endif /* SceneManager_hpp */
