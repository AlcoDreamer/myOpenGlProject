//
//  Camera.cpp
//  myOpenGlProject
//
//  Created by dchernyshev on 14.11.17.
//  Copyright © 2017 dchernyshev. All rights reserved.
//

#include "Camera.h"
#include <iostream>

Camera::Camera() {}

Camera::~Camera() {}

Camera::Camera(glm::vec3 pos, glm::vec3 vectFront, glm::vec3 vectNorm, long double speed) : Object(pos, vectFront, vectNorm) {
    this->setVectView(vectFront);
    this->setSpeed(speed);
}

void Camera::setVectView(glm::vec3 vectView) {
    this->vectView = vectView;
}

void Camera::setSpeed(long double speed) {
    this->speed = speed;
}

glm::vec3 Camera::getView() {
    return this->vectView;
}

void Camera::move() {
    float kf, ku, kr;
    kf = this->dMove.x; ku = this->dMove.y; kr = this->dMove.z;
    this->setVectRight(glm::cross(this->vectFront, this->vectNorm));
    
    this->delta = this->vectFront * kf + this->vectNorm * ku + this->vectRight * kr;
    if (this->delta != glm::vec3(0.0)) {
        this->delta = glm::normalize(this->delta) * this->speed;
    }
    //std::cerr << v.x << " " << v.y << " " << v.z << std::endl;
    //std::cerr << v2.x << " " << v2.y << " " << v2.z << std::endl;
    this->pos = this->pos + this->delta;
}

void Camera::setDeltaMove(glm::vec3 dMove) {
    this->dMove = dMove;
}

glm::vec3 Camera::getDeltaMove() {
    return this->dMove;
}

void Camera::set() {
    glm::vec3 v1, v2, v3;
    v1 = this->getPos();
    v2 = v1 + this->getView();
    v3 = this->getNorm();
    //std::cerr << "Pos  = " << v1.x << " " << v1.y << " " << v1.z << std::endl;
    //std::cerr << "To   = " << v2.x << " " << v2.y << " " << v2.z << std::endl;
    //std::cerr << "Norm = " << v3.x << " " << v3.y << " " << v3.z << std::endl;
    gluLookAt(v1.x, v1.y, v1.z,
              v2.x, v2.y, v2.z,
              v3.x, v3.y, v3.z);
}
