#ifndef SATELLITE_H
#define SATELLITE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"
#include <random>
#include "random.h"
#include <time.h>

using namespace sf;

class Satellite
{
public:
    Satellite(RenderWindow& window, int playerXpos, int playerYpos, float theta, int radius);

    void moveIncrement();

    void draw(RenderWindow& window);

    void updateMovement();

    int getXPosition();

    int getYPosition();

    int getHealth();

    void decreaseHealth(int damage);

    bool isAlive();

    void centreEntity(float angle);

    RectangleShape satellite;

private:
    float _theta;
    int _xsign;
    int _ysign;
    int _xpos;
    int _ypos;
    int _windowCentreX;
    int _windowCentreY;
    int _health = 45;
    int _radius;
};
#endif