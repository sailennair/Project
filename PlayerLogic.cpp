#include "PlayerLogic.h"

PlayerLogic::PlayerLogic(int xWindow, int yWindow)
{

    _radius = (yWindow - 70) / 2 - 20;
    //  _yPos/2 -20
}

int PlayerLogic::moveLeftX()
{
    _theta = _theta + degreesToRadians(-2);

    return (_radius)*cos(_theta);
}

int PlayerLogic::moveLeftY()
{
    _theta = _theta + degreesToRadians(-2);

    return _yPos = (_radius)*sin(_theta);
}

int PlayerLogic::moveRightY()
{
    _theta = _theta + degreesToRadians(2);
    angleOfRotation();
    return _yPos;
}

int PlayerLogic::moveRightX()
{
    _theta = _theta + degreesToRadians(2);
    angleOfRotation();
    return _xPos;
}

void PlayerLogic::angleOfRotation()
{

    _xPos = (_radius)*cos(_theta);
    _yPos = (_radius)*sin(_theta);
}

float PlayerLogic::radiansToDegrees(float x)
{
    return (x * 180) / PI;
}

float PlayerLogic::degreesToRadians(float x)
{
    return (x * PI) / 180;
}

float PlayerLogic::getAngle()
{
    return radiansToDegrees(_theta);
}

float PlayerLogic::getTheta()
{
    return _theta;
}

int PlayerLogic::getRadius()
{
    return _radius;
}