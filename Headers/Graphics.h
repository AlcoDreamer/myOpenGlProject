//
//  Graphics.h
//  MyProject
//
//  Created by dchernyshev on 04.11.17.
//  Copyright © 2017 dchernyshev. All rights reserved.
//

#ifndef Graphics_h
#define Graphics_h

#include <Glut/glut.h>
#include <stdlib.h>

void init(int * , char **);

void createWindow(int , int, int, int);

void renderer();

void loop();

void display();

void reshape(int width, int height);

#endif /* Graphics_h */
