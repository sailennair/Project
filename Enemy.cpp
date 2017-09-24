#include "Enemy.h"

Enemy::Enemy(RenderWindow& window, int playerXpos, int playerYpos, float theta)
{
   // _enemy.setSize(Vector2f(30, 30));
   
    _enemy.setSize(Vector2f(15, 15));
    _enemy.setFillColor(Color::Red);

    _windowCentreX = (window.getSize().x) / 2;

    _windowCentreY = (window.getSize().y) / 2;

    _enemy.setPosition(_windowCentreX, _windowCentreY);

    _theta = theta;

    _xpos = _enemy.getPosition().x;

    _ypos = _enemy.getPosition().y;
}

void Enemy::moveIncrement()
{
    _enemy.move((_xpos * cos(_theta)) * 0.01, (_ypos * sin(_theta)) * 0.01);
   
    _enemy.setSize(Vector2f(_enemy.getSize().x + 0.5,_enemy.getSize().y + 0.5));
    
    
    
}

void Enemy:: outOfScreenMovement(){
    _enemy.move((_xpos * cos(_theta)) * 0.01, (_ypos * sin(_theta)) * 0.01);
    _enemy.scale(1,1);
    
}

void Enemy::draw(RenderWindow& window)
{
    window.draw(_enemy);
}

int Enemy::getXPosition()
{
    return _enemy.getPosition().x;
}

int Enemy::getYPosition()
{
    return _enemy.getPosition().y;
}

void Enemy::centreEntity(float angle)
{
    
   
     _enemy.setSize(Vector2f(15, 15));
    
    
    
    _enemy.setPosition(_windowCentreX, _windowCentreY);

    _theta = angle;

    _xpos = _enemy.getPosition().x;

    _ypos = _enemy.getPosition().y;
    
    
}

void Enemy::decreaseHealth(int damage)
{
    _health -= damage;
}

int Enemy::getHealth()
{
    return _health;
}

bool Enemy::isAlive()
{
    if(_health <= 0) {
        return false;
    } else {
        return true;
    }
}

void Enemy::reSize(){
   _enemy.setSize(Vector2f(15,15));
}