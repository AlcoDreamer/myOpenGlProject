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
    mouse.motion(x, y);
}

void mousePassiveMotionFunc(int x, int y) {
    mouse.motion(x, y);
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

void Mouse::forgеtButton(int button) {
    this->_heldButton[button] = false;
    this->_pressedButton[button] = false;
    this->_releasedButton[button] = false;
}

void Mouse::setPos(glm::ivec2 pos) {
    this->oldPos = this->pos;
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
    glutWarpPointer(width / 2, height / 2);
}

bool Mouse::getWarpFlag() {
    return this->warpFlag;
}

void Mouse::motion(int x, int y) {
    mouse.setPos(glm::ivec2(x, y));
    if (mouse.getWarpFlag()) {
        mouse.setWarpFlag(false);
        mouse.clean();
    } else {
        mouse.check();
    }
}

void Mouse::check() {
    if (mouse.wasButtonPressed(GLUT_LEFT_BUTTON)) {
        mouse.mouseOn();
    }
    if (mouse.wasButtonReleased(GLUT_RIGHT_BUTTON)) {
        mouse.mouseOff();
        mouse.forgеtButton(GLUT_LEFT_BUTTON);
        mouse.forgеtButton(GLUT_RIGHT_BUTTON);
    }
    if (mouse.getMouseStatus()) {
        // смещение мыши на экране
        glm::ivec2 delta = glm::ivec2(0);
        delta = mouse.getPos() - mouse.getOldPos();
        
        // угол, на который надо повернуть относительно прошлого состояния
        float dAngelXZ = -(delta.x * mouse.getSpeed());
        float dAngelYZ = -(delta.y * mouse.getSpeed());
        
        // вычисляем суммарный угол поворота относительно дефоулта
        float angelXZ = camera.getAngelXZ() + dAngelXZ;
        float angelYZ = camera.getAngelYZ() + dAngelYZ;
        
        // аккуратно смотрим вниз и вверх
        angelYZ = fmax(-M_PI / 2, angelYZ);
        angelYZ = fmin(angelYZ, M_PI / 2);

        // матрица поворота относительно оси OY
        glm::mat3 MY = glm::mat3(cos(angelXZ), 0.0, sin(angelXZ),
                                 0.0, 1.0, 0.0,
                                 -sin(angelXZ), 0.0, cos(angelXZ));
        
        // матрица поворота относительно оси OX
        glm::mat3 MX = glm::mat3(1.0, 0.0, 0.0,
                                 0.0, cos(angelYZ), -sin(angelYZ),
                                 0.0, sin(angelYZ), cos(angelYZ));
        
        //std::cerr << delta.x << " " << delta.y << std::endl;
        
        // поворачиваем сначала вокруг OX затем вокруг OY
        glm::vec3 newVectView, newVectViewUp, newVectFront;
        newVectView   = defVectFront * MX * MY;
        newVectViewUp = defVectNorm  * MX * MY;
        std::cerr << camera.getStatus() << std::endl;
        if (camera.getStatus() == CAMERA_FREE)
            newVectFront = defVectFront * MX * MY;
        else if (camera.getStatus() == CAMERA_NOT_FREE)
            newVectFront = defVectFront * MY;
        
        // запоминаем изменения
        camera.setVectView(newVectView);
        camera.setVectViewUp(newVectViewUp);
        camera.setVectFront(newVectFront);
        
        camera.setAngelXZ(angelXZ);
        camera.setAngelYZ(angelYZ);
        
        //mouse.setWarpFlag(true);
        //mouse.setCursorInCentre(WinWidth, WinHeight);
    }
    mouse.clean();
}
