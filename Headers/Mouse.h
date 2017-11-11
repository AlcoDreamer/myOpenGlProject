//
//  Mouse.h
//  MyProject
//
//  Created by dchernyshev on 10.11.17.
//  Copyright © 2017 dchernyshev. All rights reserved.
//

#ifndef Mouse_h
#define Mouse_h

#include <Glut/glut.h>
#include <map>
#include "Geometry.h"

void mouseButtonFunc(int button, int state, int x, int y);

void mouseMotionFunc(int x, int y);

void mousePassiveMotionFunc(int x, int y);

class Mouse {
public:
    Mouse();
    Mouse(long double);
    ~Mouse();
    
    void buttonUpEvent(int);
    void buttonDownEvent(int);
    void setPos(int, int);
    
    Vect2ll getPos();
    long double getSpeed();
    
    bool wasButtonPressed(int);
    bool wasButtonReleased(int);
    bool isButtonHeld(int);

private:
    std::map < int, bool > _heldButton;
    std::map < int, bool > _pressedButton;
    std::map < int, bool > _releasedButton;
    
    int x, y;
    long double speed;
};

#endif /* Mouse_h */
