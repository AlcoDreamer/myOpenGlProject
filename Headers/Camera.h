//
//  Camera.h
//  myOpenGlProject
//
//  Created by dchernyshev on 14.11.17.
//  Copyright © 2017 dchernyshev. All rights reserved.
//

#ifndef Camera_h
#define Camera_h

#include "Object.h"

class Camera : public Object {
public:
    Camera();
    Camera(glm::vec3 pos, long double speed);
    ~Camera();
    
    void setVectView(glm::vec3);
    void setVectViewUp(glm::vec3);
    void setSpeed(long double);
    void setDeltaMove(glm::vec3);
    
    glm::vec3 getView();
    glm::vec3 getDeltaMove();
    
    float getAngelXZ();
    float getAngelYZ();
    void setAngelXZ(float);
    void setAngelYZ(float);
    
    void set();
private:
    glm::vec3 vectView, vectViewUp;
    float angelXZ, angelYZ;
};

#endif /* Camera_h */
