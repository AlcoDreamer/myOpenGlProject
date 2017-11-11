//
//  Keyboard.cpp
//  MyProject
//
//  Created by dchernyshev on 07.11.17.
//  Copyright © 2017 dchernyshev. All rights reserved.
//

#include "Keyboard.h"

extern Keyboard keyboard;

void keyDown(unsigned char key, int x, int y) {
    keyboard.keyDownEvent(key);
}

void keyUp(unsigned char key, int x, int y) {
    keyboard.keyUpEvent(key);
}

void specialKeyDown(int key, int x, int y) {
    keyboard.specialKeyDownEvent(key);
}

void specialKeyUp(int key, int x, int y) {
    keyboard.specialKeyUpEvent(key);
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
    key = tolower(key);
    this->_pressedKeys[key] = true;
    this->_heldKeys[key] = true;
}

bool Keyboard::wasKeyPressed(unsigned char key) {
    key = tolower(key);
    return _pressedKeys[key];
}

bool Keyboard::wasKeyReleased(unsigned char key) {
    key = tolower(key);
    return _releasedKeys[key];
}

bool Keyboard::isKeyHeld(unsigned char key) {
    key = tolower(key);
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
