#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class EnemyBullet
{

public:
    EnemyBullet(int xPos, int yPos, float theta);

    void fire(RenderWindow& window);

    void draw(RenderWindow& window);

    void setPos(Vector2f newPos);
    int getXPosition();
    int getYPosition();
    int getDamage();
    
    RectangleShape enemybullet;
        

private:
    
    int _bulletXpos;
    int _bulletYpos;
    int _damage = 5;
    float _theta;
    
  
};

#endif