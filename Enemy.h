#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"
#include <random>
#include "random.h"
#include <time.h>

#define PI 3.14159265

using namespace sf;

class Enemy
{
public:
    Enemy(RenderWindow& window, int playerXpos, int playerYpos, float theta);

    void moveIncrement();

    void draw(RenderWindow& window);

    void updateMovement();
    int getXPosition();
    int getYPosition();

private:
    float _theta;
    int _xsign;
    int _ysign;
    int _xpos;
    int _ypos;
    RectangleShape _enemy;
};
#endif