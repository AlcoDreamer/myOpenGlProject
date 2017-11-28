//
//  Mouse.cpp
//  MyProject
//
//  Created by dchernyshev on 10.11.17.
//  Copyright © 2017 dchernyshev. All rights reserved.
//

#include "Mouse.h"
#include "Camera.h"
#include "General.h"

extern Mouse mouse;
extern Camera camera;

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
    if (this->getWarpFlag()) {
        this->setWarpFlag(false);
        return;
    }
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

void Mouse::setWarpFlag(bool warpFlag) {
    this->warpFlag = warpFlag;
}

void Mouse::setCursorInCentre(int width, int height) {
    this->setWarpFlag(true);
    glutWarpPointer(width / 2, height / 2);
    //this->setPos(glm::ivec2(0, 0));
}

bool Mouse::getWarpFlag() {
    return this->warpFlag;
}

void Mouse::check() {
    if (mouse.isButtonHeld(GLUT_LEFT_BUTTON)) {
        mouse.mouseOn();
    }
    if (mouse.isButtonHeld(GLUT_RIGHT_BUTTON)) {
        mouse.mouseOff();
    }
    if (mouse.getMouseStatus()) {
        glm::ivec2 delta = glm::ivec2(0, 0);
        //if (mouse.getWarpFlag())
        delta = mouse.getPos() - mouse.getOldPos();
        
        //float angelXZ = asin(delta.x * mouse.getSpeed());
        //float angelYZ = asin(delta.y * mouse.getSpeed());
        
        //std::cerr << delta.x << " " << delta.y << std::endl;
        glm::vec3 nv = glm::vec3(delta.x * mouse.getSpeed(), -delta.y * mouse.getSpeed(), 0.0);
        //std::cerr << delta.x << " " << delta.y << std::endl;
        
        glm::vec3 ov = camera.getView();
        camera.setVectView((nv + ov));
        
        mouse.setCursorInCentre(WinWidth, WinHeight);
        
        //mouse.clean();
    }
}




