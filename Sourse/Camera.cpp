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

Camera::Camera(glm::vec3 pos, long double speed) : Object(pos) {
    this->setVectView(vectFront);
    this->setVectViewUp(vectNorm);
    this->setSpeed(speed);
    this->setAngelXZ(0.0);
    this->setAngelYZ(0.0);
    this->setStatus(CAMERA_NOT_FREE);
}

void Camera::setVectView(glm::vec3 vectView) {
    this->vectView = vectView;
}

void Camera::setVectViewUp(glm::vec3 vectViewUp) {
    this->vectViewUp = vectViewUp;
}

void Camera::setSpeed(long double speed) {
    this->speed = speed;
}

glm::vec3 Camera::getView() {
    return this->vectView;
}

void Camera::setDeltaMove(glm::vec3 dMove) {
    this->dMove = dMove;
}

glm::vec3 Camera::getDeltaMove() {
    return this->dMove;
}

void Camera::set() {
    glm::vec3 v1, v2, v3;
    v1 = this->pos;
    v2 = v1 + this->vectView;
    v3 = this->vectViewUp;
    //std::cerr << "Pos  = " << v1.x << " " << v1.y << " " << v1.z << std::endl;
    //std::cerr << "To   = " << v2.x << " " << v2.y << " " << v2.z << std::endl;
    //std::cerr << "Norm = " << v3.x << " " << v3.y << " " << v3.z << std::endl;
    gluLookAt(v1.x, v1.y, v1.z,
              v2.x, v2.y, v2.z,
              v3.x, v3.y, v3.z);
}

float Camera::getAngelXZ() {
    return this->angelXZ;
}

float Camera::getAngelYZ() {
    return this->angelYZ;
}

void Camera::setAngelXZ(float angel) {
    this->angelXZ = angel;
}

void Camera::setAngelYZ(float angel) {
    this->angelYZ = angel;
}

void Camera::setStatus(int newStatus) {
    this->status = newStatus;
}

int Camera::getStatus() {
    return this->status;
}
