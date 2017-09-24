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
    int getHealth();
    void decreaseHealth(int damage);
    bool isAlive();
    
    bool isFiring();
    bool isEnemyWithinScreen(const RenderWindow& window);
    
    void centreEntity(float angle);
    RectangleShape _enemy;

private:
    float _theta;
    int _xsign;
    int _ysign;
    int _xpos;
    int _ypos;
    int _windowCentreX;
    int _windowCentreY;
   // bool isAlive;
   
    //To track bullet fired time
    long unsigned int timeBulletFired;
    
    int _health = 45;
};
#endif