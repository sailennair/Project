#include "Enemy.h"

Enemy::Enemy(RenderWindow& window, int playerXpos, int playerYpos, float theta)
{
    // _enemy.setSize(Vector2f(30, 30));

    _enemy.setSize(Vector2f(20, 20));
    _enemy.setFillColor(Color::Blue);
    newScale = setScale;

    if(!_enemyTexture.loadFromFile("spacestation.png")) {
        std::cerr << "Error Loading Player Texture";
    }
    _enemyTexture.setSmooth(true);

    enemySprite.setTexture(_enemyTexture);

    _windowCentreX = (window.getSize().x) / 2;

    _windowCentreY = (window.getSize().y) / 2;

    _enemy.setPosition(_windowCentreX, _windowCentreY);

    enemySprite.setPosition(_enemy.getPosition());

    enemySprite.setScale(Vector2f(setScale, setScale));

    _theta = theta;

    _xpos = _enemy.getPosition().x;

    _ypos = _enemy.getPosition().y;

    for(auto k = 0; k < 1; k++) {
        EnemyBullet enemyBullet(getCentreX(), getCentreY(), _theta);
        enemyBulletsVec.push_back(enemyBullet);
    }
}

void Enemy::moveIncrement()
{
    _enemy.move((_xpos * cos(_theta)) * 0.0075, (_ypos * sin(_theta)) * 0.0075);

    _enemy.setSize(Vector2f(_enemy.getSize().x + 0.5, _enemy.getSize().y + 0.5));

    rectScale = (((_enemy.getSize().x + 0.5) / (_enemy.getSize().x)) - 1) * 0.1;
    newScale += rectScale;

    enemySprite.setTexture(_enemyTexture);

    enemySprite.setScale(Vector2f(newScale, newScale));

    enemySprite.setPosition(_enemy.getPosition());
    enemySprite.setTexture(_enemyTexture);
}

void Enemy::outOfScreenMovement()
{
    _enemy.move((_xpos * cos(_theta)) * 0.01, (_ypos * sin(_theta)) * 0.01);
    _enemy.scale(1, 1);
    enemySprite.setTexture(_enemyTexture);
    enemySprite.setPosition(_enemy.getPosition());
}

void Enemy::draw(RenderWindow& window)
{
    //  window.draw(_enemy);
    window.draw(enemySprite);
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

    _enemy.setSize(Vector2f(20, 20));
    newScale = setScale;
    _enemy.setPosition(_windowCentreX, _windowCentreY);
    enemySprite.setScale(Vector2f(setScale, setScale));
    enemySprite.setTexture(_enemyTexture);

    enemySprite.setPosition(_enemy.getPosition());

    _theta = angle;

    _xpos = _enemy.getPosition().x;

    _ypos = _enemy.getPosition().y;

    enemyBulletsVec.erase(enemyBulletsVec.begin(), enemyBulletsVec.end());

    for(auto k = 0; k < 1; k++) {
        EnemyBullet enemyBullet(_xpos, _ypos, _theta);
        enemyBulletsVec.push_back(enemyBullet);
    }
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

void Enemy::reSize()
{
    _enemy.setSize(Vector2f(15, 15));
}

int Enemy::getCentreX()
{
    _centreX = _enemy.getPosition().x + (_enemy.getSize().x / 2);
    return _centreX;
}

int Enemy::getCentreY()
{
    _centreY = _enemy.getPosition().y + (_enemy.getSize().y / 2);
    return _centreY;
}

float Enemy::getTheta()
{
    return _theta;
}

// bool Enemy::shouldFire(){
//    return true;
//}

int Enemy::getDamage()
{
    return _damage;
}

void Enemy::setDamage(int damage)
{
    _damage = damage;
}
