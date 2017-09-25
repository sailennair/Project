#ifndef PLAYERLOGIC_H
#define PLAYERLOGIC_H

#include <iostream>
#include <math.h>
#include "GameWindow.h"

#define PI 3.14159265

class PlayerLogic
{

public:
    PlayerLogic(int xWindow, int yWindow);
    int moveLeftX();
    int moveLeftY();
    int moveRightX();
    int moveRightY();
    void angleOfRotation();
    float getAngle();
    float getTheta();
    int getRadius();
    int getHealth();
    void reduceHealth(int damage);
    bool isAlive();

private:
    float _theta = (PI) / 2;

    int _radius;
    int _xPos;
    int _yPos;
    int _health = 100;
    float radiansToDegrees(float x);
    float degreesToRadians(float x);
};
#endif