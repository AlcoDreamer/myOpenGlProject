//
//  Object.h
//  MyProject
//
//  Created by dchernyshev on 08.11.17.
//  Copyright © 2017 dchernyshev. All rights reserved.
//

#ifndef Object_h
#define Object_h

#include <Glut/glut.h>
#include "Geometry.h"

class Object {
public:
    Object();
    Object(Vect3ld, Vect3ld, Vect3ld, long double);
    ~Object();
    
    void setPos(Vect3ld);
    void setVectFront(Vect3ld);
    void setVectUp(Vect3ld);
    void setVectRight(Vect3ld);
    void setVectView(Vect3ld);
    void setSpeed(long double);
    
    Vect3ld getPos();
    Vect3ld getFront();
    Vect3ld getView();
    Vect3ld getNorm();
    
    void move(long double, long double, long double);

private:
    Vect3ld pos, delta, vectUp, vectFront, vectRight, vectView;
    long double speed;
};

#endif /* Object_h */
