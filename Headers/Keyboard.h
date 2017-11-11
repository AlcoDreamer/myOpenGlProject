//
//  Keyboard.h
//  MyProject
//
//  Created by dchernyshev on 07.11.17.
//  Copyright © 2017 dchernyshev. All rights reserved.
//

#ifndef Keyboard_h
#define Keyboard_h

#include <Glut/glut.h>
#include <map>

void keyDown(unsigned char key, int x, int y);

void keyUp(unsigned char key, int x, int y);

void specialKeyDown(int key, int x, int y);

void specialKeyUp(int key, int x, int y);

class Keyboard
{
public:
    Keyboard();
    ~Keyboard();
    
    void beginNewFrame();
    
    void keyUpEvent(unsigned char key);
    void keyDownEvent(unsigned char key);
    
    bool wasKeyPressed(unsigned char key);
    bool wasKeyReleased(unsigned char key);
    bool isKeyHeld(unsigned char key);

    void specialKeyUpEvent(int key);
    void specialKeyDownEvent(int key);
    
    bool wasSpecialKeyPressed(int key);
    bool wasSpecialKeyReleased(int key);
    bool isSpecialKeyHeld(int key);

private:
    std::map < unsigned char, bool > _heldKeys;
    std::map < unsigned char, bool > _pressedKeys;
    std::map < unsigned char, bool > _releasedKeys;
    
    std::map < int, bool > _heldSpecialKeys;
    std::map < int, bool > _pressedSpecialKeys;
    std::map < int, bool > _releasedSpecialKeys;
};


#endif /* Keyboard_h */
