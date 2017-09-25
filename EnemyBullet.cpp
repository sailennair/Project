#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(int xPos, int yPos, float theta)
{
   
    enemybullet.setSize(Vector2f(5,5));
    
    enemybullet.setFillColor(Color::Red);

//needs to get position of enemy centre, then dont need to rotate enemy
    enemybullet.setPosition(xPos, yPos);
    
    
    _bulletXpos = enemybullet.getPosition().x;
    
    _xpos = xPos;
    _ypos = yPos;

    _bulletYpos = enemybullet.getPosition().y;
    
    //need the angle of the enemy direction
    _theta = theta ;//+PI/6;
    
    
}



void EnemyBullet::fire(RenderWindow& window)
{
 
    

    auto xIncrement = (_xpos * cos(_theta)) * 0.01;

    auto yIncrement = (_ypos * sin(_theta)) * 0.01;

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