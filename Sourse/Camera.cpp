//
//  Camera.cpp
//  myOpenGlProject
//
//  Created by dchernyshev on 14.11.17.
//  Copyright © 2017 dchernyshev. All rights reserved.
//

#include "Camera.h"

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

void Camera::move(float kf, float ku, float kr) {
    this->setVectRight(glm::cross(this->vectFront, this->vectNorm));
    
    this->delta = this->vectFront * kf + this->vectNorm * ku + this->vectRight * kr;
    if (this->delta != glm::vec3(0.0)) {
        this->delta = glm::normalize(this->delta) * this->speed;
    }
    //std::cerr << v.x << " " << v.y << " " << v.z << std::endl;
    //std::cerr << v2.x << " " << v2.y << " " << v2.z << std::endl;
    this->pos = this->pos + this->delta;
}