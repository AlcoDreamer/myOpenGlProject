//
//  Mouse.cpp
//  MyProject
//
//  Created by dchernyshev on 10.11.17.
//  Copyright © 2017 dchernyshev. All rights reserved.
//

#include "Mouse.h"

extern Mouse mouse;

void mouseButtonFunc(int button, int state, int x, int y) {
    if (state == GLUT_DOWN)
        mouse.buttonDownEvent(button);
    if (state == GLUT_UP)
        mouse.buttonUpEvent(button);
}

void mouseMotionFunc(int x, int y) {
    mouse.setPos(glm::ivec2(x, y));
}

void mousePassiveMotionFunc(int x, int y) {
    mouse.setPos(glm::ivec2(x, y));
}

Mouse::Mouse() {}

Mouse::Mouse(long double speed) {
    this->speed = speed;
}

Mouse::~Mouse() {}

void Mouse::buttonUpEvent(int button) {
    this->_releasedButton[button] = true;
    this->_heldButton[button] = false;
}

void Mouse::buttonDownEvent(int button) {
    this->_pressedButton[button] = true;
    this->_heldButton[button] = true;
}

bool Mouse::isButtonHeld(int button) {
    return this->_heldButton[button];
}

bool Mouse::wasButtonPressed(int button) {
    return this->_pressedButton[button];
}

bool Mouse::wasButtonReleased(int button) {
    return this->_releasedButton[button];
}

void Mouse::setPos(glm::ivec2 pos) {
    this->oldPos =  this->pos;
    this->pos = pos;
}

void Mouse::clean() {
    this->oldPos =  this->pos;
}

glm::ivec2 Mouse::getPos() {
    return this->pos;
}

glm::ivec2 Mouse::getOldPos() {
    return this->oldPos;
}

long double Mouse::getSpeed() {
    return this->speed;
}

void Mouse::mouseOn() {
    this->mouseStatus = true;
}

void Mouse::mouseOff() {
    this->mouseStatus = false;
}

bool Mouse::getMouseStatus() {
    return this->mouseStatus;
}
