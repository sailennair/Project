#include "Enemy.h"

Enemy::Enemy(RenderWindow& window, int playerXpos, int playerYpos, float theta)
{
    _enemy.setSize(Vector2f(30, 30));
    _enemy.setFillColor(Color::Red);

    _windowCentreX = (window.getSize().x) / 2;

    _windowCentreY = (window.getSize().y) / 2;

    _enemy.setPosition(_windowCentreX, _windowCentreY);

    _theta = theta;

    _xpos = _enemy.getPosition().x;

    _ypos = _enemy.getPosition().y;
    
    // initializing to some random time so first bullet is shot faster
     timeBulletFired = 500-00;
}

void Enemy::moveIncrement()
{
    _enemy.move((_xpos * cos(_theta)) * 0.01, (_ypos * sin(_theta)) * 0.01);
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


// This is que query to see if a shot is fired by Enemy
bool Enemy::isFiring(){
    timeBulletFired++;
    
    if (timeBulletFired>100-000-000-000-000-000)
        return true;
        
    return false;
}

bool Enemy::isEnemyWithinScreen(const RenderWindow& window){
    
        if((_enemy.getPosition().x < 0) ||
            (_enemy.getPosition().x > window.getSize().x ) ||
            (_enemy.getPosition().y < 0) ||
            (_enemy.getPosition().y > window.getSize().y)) {
            
            return false;
        }
        
    return true;
}