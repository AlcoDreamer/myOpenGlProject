//
//  Keyboard.cpp
//  MyProject
//
//  Created by dchernyshev on 07.11.17.
//  Copyright © 2017 dchernyshev. All rights reserved.
//

#include "Keyboard.h"
#include "Camera.h"
#include <iostream>

extern Keyboard keyboard;
extern Camera camera;

void keyDown(unsigned char key, int x, int y) {
    key = tolower(key);
    keyboard.keyDownEvent(key);
    keyboard.check();
}

void keyUp(unsigned char key, int x, int y) {
    key = tolower(key);
    keyboard.keyUpEvent(key);
    keyboard.check();
}

void specialKeyDown(int key, int x, int y) {
    keyboard.specialKeyDownEvent(key);
    keyboard.check();
}

void specialKeyUp(int key, int x, int y) {
    keyboard.specialKeyUpEvent(key);
    keyboard.check();
}

Keyboard::Keyboard() {}

Keyboard::~Keyboard() {}

void Keyboard::beginNewFrame() {
    this->_pressedKeys.clear();
    this->_releasedKeys.clear();
    this->_pressedSpecialKeys.clear();
    this->_releasedSpecialKeys.clear();
}

void Keyboard::keyUpEvent(unsigned char key) {
    key = tolower(key);
    this->_releasedKeys[key] = true;
    this->_heldKeys[key] = false;
}

void Keyboard::keyDownEvent(unsigned char key) {
    this->_pressedKeys[key] = true;
    this->_heldKeys[key] = true;
}

bool Keyboard::wasKeyPressed(unsigned char key) {
    return _pressedKeys[key];
}

bool Keyboard::wasKeyReleased(unsigned char key) {
    return _releasedKeys[key];
}

bool Keyboard::isKeyHeld(unsigned char key) {
    return _heldKeys[key];
}

void Keyboard::specialKeyUpEvent(int key) {
    this->_releasedSpecialKeys[key] = true;
    this->_heldSpecialKeys[key] = false;
}

void Keyboard::specialKeyDownEvent(int key) {
    this->_pressedSpecialKeys[key] = true;
    this->_heldSpecialKeys[key] = true;
}

bool Keyboard::wasSpecialKeyPressed(int key) {
    return _pressedSpecialKeys[key];
}

bool Keyboard::wasSpecialKeyReleased(int key) {
    return _releasedSpecialKeys[key];
}

bool Keyboard::isSpecialKeyHeld(int key) {
    return _heldSpecialKeys[key];
}

void Keyboard::check() {
    long double df, dr, du;
    df = dr = du = 0;
    if (this->wasKeyPressed(27))
        exit(0);
    if (this->isKeyHeld('w')) {
        df = 1;
    }
    if (this->isKeyHeld('s')) {
        df = -1;
    }
    if (this->isKeyHeld('a')) {
        dr = -1;
    }
    if (this->isKeyHeld('d')) {
        dr = 1;
    }
    if (this->isSpecialKeyHeld(GLUT_KEY_UP)) {
        du = 1;
    }
    if (this->isSpecialKeyHeld(GLUT_KEY_DOWN)) {
        du = -1;
    }
    camera.setDeltaMove(glm::vec3(df, du, dr));
    
    if (this->wasKeyPressed('1')) {
        this->forgеtKey('1');
        this->forgеtKey('2');
        camera.setStatus(CAMERA_FREE);
    }
    if (this->wasKeyPressed('2')) {
        this->forgеtSpecialKey('2');
        this->forgеtKey('1');
        camera.setStatus(CAMERA_NOT_FREE);
    }
}

void Keyboard::forgеtKey(unsigned char key) {
    this->_heldKeys[key] = false;
    this->_pressedKeys[key] = false;
    this->_releasedKeys[key] = false;
}

void Keyboard::forgеtSpecialKey(int key) {
    this->_heldSpecialKeys[key] = false;
    this->_pressedSpecialKeys[key] = false;
    this->_releasedSpecialKeys[key] = false;
}
