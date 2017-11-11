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

Object::Object(glm::vec3 pos, glm::vec3 vectFront, glm::vec3 vectUp, long double speed) {
    this->setPos(pos);
    this->setVectFront(vectFront);
    this->setVectView(vectFront);
    this->setVectUp(vectUp);
    this->setVectRight(this->vectFront * this->vectUp);
    this->setSpeed(speed);
}

Object::~Object() {}

void Object::setPos(glm::vec3 pos) {
    this->pos = pos;
}

void Object::setVectFront(glm::vec3 vectFront) {
    this->vectFront = vectFront;
}

void Object::setVectUp(glm::vec3 vectUp) {
    this->vectUp = vectUp;
}

void Object::setVectRight(glm::vec3 vectRight) {
    this->vectRight = vectRight;
}

void Object::setVectView(glm::vec3 vectView) {
    this->vectView = vectView;
}

void Object::setSpeed(long double speed) {
    this->speed = speed;
}

glm::vec3 Object::getPos() {
    return this->pos;
}

glm::vec3 Object::getFront() {
    return this->vectFront;
}

glm::vec3 Object::getView() {
    return this->vectView;
}

glm::vec3 Object::getNorm() {
    return this->vectUp;
}

void Object::move(float kf, float ku, float kr) {
    this->setVectRight(glm::cross(this->vectFront, this->vectUp));
    
    this->delta = this->vectFront * kf + this->vectUp * ku + this->vectRight * kr;
    if (this->delta != glm::vec3(0.0)) {
        this->delta = glm::normalize(this->delta) * this->speed;
    }
    //std::cerr << v.x << " " << v.y << " " << v.z << std::endl;
    //std::cerr << v2.x << " " << v2.y << " " << v2.z << std::endl;
    this->pos = this->pos + this->delta;
}
