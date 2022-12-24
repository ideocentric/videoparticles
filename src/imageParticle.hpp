//
//  imageParticle.hpp
//  videoparticles
//
//  Created by Matt Comeione on 12/23/22.
//

#ifndef imageParticle_hpp
#define imageParticle_hpp

#include "ofMain.h"

class imageParticle {
public:
    static ofImage dot;
    ofColor color;
    bool growing;
    bool dead;
    float currsize;
    float size;
    glm::vec2 force;
    glm::vec2 position;
    glm::vec2 direction;
    
    static void setup();
    void update();
    void draw();
    
    imageParticle(int x, int y, int hue);
    imageParticle(int x, int y, ofColor c, float s);
    ~imageParticle();
};

#endif /* imageParticle_hpp */
