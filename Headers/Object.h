//
//  Object.h
//  MyProject
//
//  Created by dchernyshev on 08.11.17.
//  Copyright © 2017 dchernyshev. All rights reserved.
//

#ifndef Object_h
#define Object_h

#include <Glut/glut.h>
#include "glm/glm.hpp"

class Object {
public:
    Object();
    Object(glm::vec3, glm::vec3, glm::vec3, long double);
    ~Object();
    
    void setPos(glm::vec3);
    void setVectFront(glm::vec3);
    void setVectUp(glm::vec3);
    void setVectRight(glm::vec3);
    void setVectView(glm::vec3);
    void setSpeed(long double);
    
    glm::vec3 getPos();
    glm::vec3 getFront();
    glm::vec3 getView();
    glm::vec3 getNorm();
    
    void move(float, float, float);

private:
    glm::vec3 pos, delta, vectUp, vectFront, vectRight, vectView;
    float speed;
};

#endif /* Object_h */
