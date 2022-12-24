//
//  cameraParticles.hpp
//  videoparticles
//
//  Created by Matt Comeione on 12/23/22.
//

#ifndef cameraParticles_hpp
#define cameraParticles_hpp

#include "ofMain.h"
#include "imageParticle.hpp"

class cameraParticles {
public:
    void setup();
    void update();
    void draw();
    ofVideoGrabber webcam;
    vector<imageParticle> particles;
    int w;
    int h;
};

#endif /* cameraParticles_hpp */
