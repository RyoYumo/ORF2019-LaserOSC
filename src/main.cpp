#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){


	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
    
    ofGLFWWindowSettings settings;
    settings.setPosition(glm::vec2(0,0));
    settings.setSize(1920, 1080);
    settings.setGLVersion(2, 1);
//    settings.setPosition(glm::vec2(1920, 0));
    settings.decorated = false;

    auto window = ofCreateWindow(settings);
    auto app    = std::make_shared<ofApp>();
    
    ofRunApp(window, app);
    ofRunMainLoop();
}
