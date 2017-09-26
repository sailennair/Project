#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"
#include <random>
#include "random.h"
#include <time.h>
#include <vector>
#include "EnemyBullet.h"
//#include <RectangleShape.hpp>

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
    void reSize();
    void outOfScreenMovement();
    int getCentreX();

    int getCentreY();
    float getTheta();

    std::vector<EnemyBullet> enemyBulletsVec;

    void centreEntity(float angle);
    RectangleShape _enemy;
    int getDamage();
    void setDamage(int damage);

private:
    float _theta;
    int _xsign;
    int _ysign;
    int _xpos;
    int _ypos;
    int _centreX;
    int _centreY;
    int _windowCentreX;
    int _windowCentreY;
    float rectScale;
    float setScale = 0.03;
    float newScale;
    Sprite enemySprite;
    Texture _enemyTexture;
    int _damage = 100;

    bool _shouldFire;

    // bool isAlive;

    int _health = 45;
};
#endif