//
//  cameraParticles.cpp
//  videoparticles
//
//  Created by Matt Comeione on 12/23/22.
//

#include "cameraParticles.hpp"


void cameraParticles::setup(){
    webcam.setup(320, 180);
    webcam.setDesiredFrameRate(15);
    w = webcam.getWidth();
    h = webcam.getHeight();
    imageParticle::setup();
}


void cameraParticles::update() {
    webcam.update();
    if(webcam.isFrameNew()) {
        for (int i=0; i<particles.size(); i++) {
            particles[i].update();
        }
    }
    for(vector<imageParticle>::iterator it = particles.begin(); it != particles.end();++it)
    {
        if( (*it).dead)
        {
            it = particles.erase(it);
        }
    }
}

void cameraParticles::draw() {
    int grid = 16;
    for( int x=0; x<w; x+=grid ) {
        for(int y=0; y<h; y+=grid ) {
            if(ofRandom(0, 1.0) >= 0.90) {
                ofColor color = webcam.getPixels().getColor(x,y);
                float brightness = color.getBrightness();
                int hue = color.getHue();
                float isize = ofMap(brightness, 0, 255, 64, 256);
                imageParticle newParticle(round(x*3),round(y*3), color, isize);
                particles.push_back(newParticle);
            }
        }
    }
    for(vector<imageParticle>::iterator it = particles.begin(); it != particles.end();++it)
    {
        (*it).draw();
    }
}
