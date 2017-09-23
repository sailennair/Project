#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>


using namespace sf;

class GameWindow
{

public:
    GameWindow(int Xwindow, int Ywindow);
    void createWindow();

    int getXCentre();
    int getYCentre();
    int getXWindow();
    int getYWindow();
    // int _radius;

private:
    int _xCentre;
    int _yCentre;
    int _Xwindow;
    int _Ywindow;
  
};
#endif