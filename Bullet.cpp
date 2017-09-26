#include "Bullet.h"

Bullet::Bullet(int xPos, int yPos, float theta, int radius, int type)
{

    if(type == 1) {
        bullet.setSize(Vector2f(5, 5));
        bullet.setFillColor(Color::Green);
        _damage = 5;
    }
    if(type == 2) {
        bullet.setSize(Vector2f(10, 10));
        bullet.setFillColor(Color::Red);
        _damage = 20;
    }
    _theta = theta - PI/2;

    //bullet.setPosition(xPos + radius * cos(theta) + 23 * cos(theta), yPos + radius * sin(theta));
    bullet.setPosition(xPos + 24*cos(_theta) , yPos + 24*sin(_theta) );
    std:: cout<< theta << std::endl;
    
}

void Bullet::fire(RenderWindow& window)
{

    auto speedOfBulletInPixels = 25;

    int xCenterOfWindow = (window.getSize().x) / 2;

    int yCenterOfWindow = (window.getSize().y) / 2;

    auto radius = (window.getSize().y - 70) / 2 - 20;

    auto xIncrement = speedOfBulletInPixels * (xCenterOfWindow - bullet.getPosition().x) / radius;

    auto yIncrement = speedOfBulletInPixels * (yCenterOfWindow - bullet.getPosition().y) / radius;

    bullet.move(xIncrement, yIncrement);
}

void Bullet::draw(RenderWindow& window)
{
    window.draw(bullet);
}

void Bullet::setPos(Vector2f newPos)
{
    bullet.setPosition(newPos);
}

int Bullet::getXPosition()
{
    return bullet.getPosition().x;
}

int Bullet::getYPosition()
{
    return bullet.getPosition().y;
}

int Bullet::getDamage()
{
    return _damage;
}

void Bullet::setDamage(int damage){
    _damage = damage;
}