//
//  Graphics.cpp
//  MyProject
//
//  Created by dchernyshev on 04.11.17.
//  Copyright © 2017 dchernyshev. All rights reserved.
//

#include "Graphics.h"

int curWinWidth = WinWidth;
int curWinHeight = WinHeight;

Keyboard keyboard;
Mouse mouse(0.01);
Camera camera(glm::vec3(0.0, 0.0, 10.0), glm::vec3(0.0, 0.0, -1.0), glm::vec3(0.0, 1.0, 0.0), 0.1);

void init(int * argc, char ** argv) {
    //std::cerr << camera.getNorm().x << camera.getNorm().y << camera.getNorm().z << std::endl;
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
}

void createWindow(int width, int height, int posx, int posy) {
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(posx, posy);
    glutCreateWindow("MyGame");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    
    // keyboard
    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);
    glutSpecialFunc(specialKeyDown);
    glutSpecialUpFunc(specialKeyUp);
    
    // mouse
    glutMouseFunc(mouseButtonFunc);
    glutMotionFunc(mouseMotionFunc);
    glutPassiveMotionFunc(mousePassiveMotionFunc);
    //glutSetCursor(GLUT_CURSOR_NONE);
    //glutFullScreen();
    
}

void loop() {
    glutMainLoop();
}

void drawPiramid() {
    glBegin(GL_TRIANGLES);
        glColor3f(0.0f,0.0f,1.0f);  glVertex3f( 1.0f,-1.0f, 1.0f);
        glColor3f(1.0f,0.0f,0.0f);  glVertex3f( 0.0f, 1.0f, 0.0f);
        glColor3f(0.0f,1.0f,0.0f);  glVertex3f(-1.0f,-1.0f, 1.0f);
    
        glColor3f(1.0f,0.0f,0.0f);  glVertex3f( 0.0f, 1.0f, 0.0f);                  // Верх треугольника (Правая)
        glColor3f(0.0f,0.0f,1.0f);  glVertex3f( 1.0f,-1.0f, 1.0f);                  // Лево треугольника (Правая)
        glColor3f(0.0f,1.0f,0.0f);  glVertex3f( 1.0f,-1.0f, -1.0f);                 // Право треугольника (Правая)
    
    
        glColor3f(1.0f,0.0f,0.0f);  glVertex3f( 0.0f, 1.0f, 0.0f);                  // Низ треугольника (Сзади)
        glColor3f(0.0f,1.0f,0.0f);  glVertex3f( 1.0f,-1.0f, -1.0f);                 // Лево треугольника (Сзади)
        glColor3f(0.0f,0.0f,1.0f);  glVertex3f(-1.0f,-1.0f, -1.0f);                 // Право треугольника (Сзади)
    
        glColor3f(1.0f,0.0f,0.0f);  glVertex3f( 0.0f, 1.0f, 0.0f);                  // Верх треугольника (Лево)
        glColor3f(0.0f,0.0f,1.0f);  glVertex3f(-1.0f,-1.0f,-1.0f);                  // Лево треугольника (Лево)
        glColor3f(0.0f,1.0f,0.0f);  glVertex3f(-1.0f,-1.0f, 1.0f);                  // Право треугольника (Лево)
    
    glEnd();
    
}

void drawSnowMan() {
    
    glColor3f(1.0f, 1.0f, 1.0f);
    
    // Draw Body
    glTranslatef(0.0f ,0.75f, 0.0f);
    glutSolidSphere(0.75f,20,20);
    
    // Draw Head
    glTranslatef(0.0f, 1.0f, 0.0f);
    glutSolidSphere(0.25f,20,20);
    
    // Draw Eyes
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    glTranslatef(0.05f, 0.10f, 0.18f);
    glutSolidSphere(0.05f,10,10);
    glTranslatef(-0.1f, 0.0f, 0.0f);
    glutSolidSphere(0.05f,10,10);
    glPopMatrix();
    
    // Draw Nose
    glColor3f(1.0f, 0.5f , 0.5f);
    glutSolidCone(0.08f,0.5f,10,2);
}

void display() {

    keyboard.check();
    mouse.check();
    //std::cerr << camera.getPos().x << " " << camera.getPos().y << " " << camera.getPos().z << std::endl;
    camera.move();
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    camera.set();
    
    drawPiramid();
    drawSnowMan();
    
    glutSwapBuffers();
}

void reshape(int width, int height) {
    curWinWidth = width;
    curWinHeight = height;

    height = std::max(1, height);
    float ratio = (1.0 * width) / height;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, width, height);

    gluPerspective(45, ratio, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}


