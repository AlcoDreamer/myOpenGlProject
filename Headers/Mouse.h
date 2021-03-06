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
#include "glm/glm.hpp"
#include <map>

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
    void setPos(glm::ivec2);
    void setWarpFlag(bool warpFlag);
    
    glm::ivec2 getPos();
    glm::ivec2 getOldPos();
    long double getSpeed();
    
    bool wasButtonPressed(int);
    bool wasButtonReleased(int);
    bool isButtonHeld(int);
    void forgеtButton(int);

    void mouseOn();
    void mouseOff();
    void clean();
    void check();
    void motion(int x, int y);
    void setCursorInCentre(int WinH, int WinW);
    bool getMouseStatus();
    bool getWarpFlag();
    
private:
    std::map < int, bool > _heldButton;
    std::map < int, bool > _pressedButton;
    std::map < int, bool > _releasedButton;
    
    glm::ivec2 pos, oldPos;
    bool mouseStatus, warpFlag;
    long double speed;
};

#endif /* Mouse_h */
