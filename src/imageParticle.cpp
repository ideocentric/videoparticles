//
//  imageParticle.cpp
//  videoparticles
//
//  Created by Matt Comeione on 12/23/22.
//

#include "imageParticle.hpp"

ofImage imageParticle::dot;

imageParticle::imageParticle(int startX, int startY, int hue) {
    position = glm::vec2(startX, startY);
    direction = glm::vec2(ofRandom(-1.0, 1.0), ofRandom(-1.0, 1.0));
    force = glm::vec2(0, 0.02);
    currsize = 0;
    size = ofRandom(32, 128);
    color.setHsb(hue, 255, 255);
    growing = true;
    dead = false;
}

imageParticle::imageParticle(int startX, int startY, ofColor initColor, float initSize){
    position = glm::vec2(startX, startY);
    direction = glm::vec2(ofRandom(-0.5, 0.5), ofRandom(-0.5, 0.5));
    currsize = 0;
    size = initSize;
    force = glm::vec2(0, 0.02);
    color = initColor;
    growing = true;
    dead = false;
}

imageParticle::~imageParticle(){
    
}

void imageParticle::setup() {
    dot.load("dot.png");
}


void imageParticle::update() {
    position += direction;
    direction += force;
    if(position.x < -128 || position.x > (ofGetWidth() + 128) || position.y > (ofGetHeight()+128))
    {
        dead = true;
    }
    if(growing)
    {
        if(currsize >= size)
        {
            growing = false;
        }
        else {
            currsize += 0.25;
        }
    } else {
        if(currsize > 1)
        {
            currsize -= 0.07;
        }
    }
    float brightness = color.getBrightness();
    if(growing) {
        color.setBrightness(brightness);
    } else {
        if(brightness > 0.5)
        {
            color.setBrightness(brightness -= 0.5);
        }
        else
        {
            color.setBrightness(brightness = 0);
            dead = true;
        }
    }
}

void imageParticle::draw() {
    ofEnableAlphaBlending();
    ofBlendMode(OF_BLENDMODE_MULTIPLY);
    dot.setAnchorPercent(0.5, 0.5);
    dot.draw(position, currsize, currsize);
    ofSetColor(color);
    ofRectangle(position,currsize,currsize);
}
