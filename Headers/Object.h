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
    Object(glm::vec3 pos, glm::vec3 front, glm::vec3 norm);
    ~Object();
    
    void setPos(glm::vec3);
    void setVectFront(glm::vec3);
    void setVectNorm(glm::vec3);
    void setVectRight(glm::vec3);

    glm::vec3 getPos();
    glm::vec3 getFront();
    glm::vec3 getNorm();

    void move();
protected:
    glm::vec3 pos, vectFront, vectNorm, vectRight, delta, dMove;
    float speed;
};

#endif /* Object_h */
