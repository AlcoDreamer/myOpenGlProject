//
//  main.cpp
//  MyProject
//
//  Created by dchernyshev on 23.10.17.
//  Copyright © 2017 dchernyshev. All rights reserved.
//


#include "General.h"
#include "Graphics.h"

int main(int argc, char ** argv) {
    
    init(&argc, argv);
    
    createWindow(WinWidth, WinHeight, WinPosX, WinPosY);
    loop();
    
    return 0;
}
