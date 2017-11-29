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
    Camera(glm::vec3 pos, glm::vec3 front, glm::vec3 norm, long double speed);
    ~Camera();
    
    void setVectView(glm::vec3);
    void setSpeed(long double);
    void setDeltaMove(glm::vec3);
    
    glm::vec3 getView();
    glm::vec3 getDeltaMove();
    
    void set();
private:
    glm::vec3 vectView;
};

#endif /* Camera_h */
