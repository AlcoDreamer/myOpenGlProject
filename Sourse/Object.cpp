//
//  Object.cpp
//  MyProject
//
//  Created by dchernyshev on 08.11.17.
//  Copyright © 2017 dchernyshev. All rights reserved.
//

#include "Object.h"
#include <iostream>

Object::Object() {}

Object::Object(glm::vec3 pos, glm::vec3 vectFront, glm::vec3 vectNorm) {
    this->setPos(pos);
    this->setVectFront(vectFront);
    this->setVectNorm(vectNorm);
    this->setVectRight(glm::cross(this->vectFront, this->vectNorm));
}

Object::~Object() {}

void Object::setPos(glm::vec3 pos) {
    this->pos = pos;
}

void Object::setVectFront(glm::vec3 vectFront) {
    this->vectFront = vectFront;
}

void Object::setVectNorm(glm::vec3 vectNorm) {
    this->vectNorm = vectNorm;
    //std::cerr << this->vectNorm.x << this->vectNorm.y << this->vectNorm.z << std::endl;
}

void Object::setVectRight(glm::vec3 vectRight) {
    this->vectRight = vectRight;
}

glm::vec3 Object::getPos() {
    return this->pos;
}

glm::vec3 Object::getFront() {
    return this->vectFront;
}

glm::vec3 Object::getNorm() {
    return this->vectNorm;
}

void Object::move() {
    float kf, ku, kr;
    kf = this->dMove.x; ku = this->dMove.y; kr = this->dMove.z;
    this->setVectRight(glm::cross(this->vectFront, this->vectNorm));
    
    this->delta = this->vectFront * kf + this->vectNorm * ku + this->vectRight * kr;
    if (this->delta != glm::vec3(0.0)) {
        this->delta = glm::normalize(this->delta) * this->speed;
    }
    this->pos = this->pos + this->delta;
}

