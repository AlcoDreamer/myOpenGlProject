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

Object::Object(Vect3ld pos, Vect3ld vectFront, Vect3ld vectUp, long double speed) {
    this->setPos(pos);
    this->setVectFront(vectFront);
    this->setVectView(vectFront);
    this->setVectUp(vectUp);
    this->setVectRight(this->vectFront * this->vectUp);
    this->setSpeed(speed);
}

Object::~Object() {}

void Object::setPos(Vect3ld pos) {
    this->pos = pos;
}

void Object::setVectFront(Vect3ld vectFront) {
    this->vectFront = vectFront;
}

void Object::setVectUp(Vect3ld vectUp) {
    this->vectUp = vectUp;
}

void Object::setVectRight(Vect3ld vectRight) {
    this->vectRight = vectRight;
}

void Object::setVectView(Vect3ld vectView) {
    this->vectView = vectView;
}

void Object::setSpeed(long double speed) {
    this->speed = speed;
}

Vect3ld Object::getPos() {
    return this->pos;
}

Vect3ld Object::getFront() {
    return this->vectFront;
}

Vect3ld Object::getView() {
    return this->vectView;
}

Vect3ld Object::getNorm() {
    return this->vectUp;
}

void Object::move(long double kf, long double ku, long double kr) {
    this->setVectRight(this->vectFront * this->vectUp);
    this->pos = this->pos + (this->vectFront * kf + this->vectUp * ku + this->vectRight * kr).normal(speed);
}
