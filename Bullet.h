#ifndef BULLET_H
#define BULLET_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Bullet
{

public:
    Bullet(int xPos, int yPos, float theta, int radius, int type);

    void fire(RenderWindow& window);

    void draw(RenderWindow& window);

    void setPos(Vector2f newPos);
    int getXPosition();
    int getYPosition();
    int getDamage();
    void setDamage(int damage);
    
    RectangleShape bullet;
        

private:
    
    
    int _damage = 5;
    
  
};

#endif