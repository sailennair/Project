#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(int xPos, int yPos, float theta)
{
   
    enemybullet.setSize(Vector2f(5,5));
    enemybullet.setFillColor(Color::Red);

    enemybullet.setPosition(xPos, yPos);
    
    _bulletXpos = enemybullet.getPosition().x;

    _bulletYpos = enemybullet.getPosition().y;
    _theta = theta;
}



void EnemyBullet::fire(RenderWindow& window)
{
 

    auto xIncrement = (_bulletXpos * cos(_theta)) * 0.1;

    auto yIncrement = (_bulletYpos * sin(_theta)) * 0.1;

    enemybullet.move(xIncrement, yIncrement);
   
}

void EnemyBullet::draw(RenderWindow &window){
    window.draw(enemybullet);
}

void EnemyBullet::setPos(Vector2f newPos){
    enemybullet.setPosition(newPos);
}

int EnemyBullet::getXPosition(){
    return enemybullet.getPosition().x;
}

int EnemyBullet::getYPosition(){
    return enemybullet.getPosition().y;
}

int EnemyBullet::getDamage(){
    return _damage;
}