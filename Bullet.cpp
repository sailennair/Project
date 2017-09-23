#include "Bullet.h"

Bullet::Bullet(int xPos, int yPos, float theta, int radius)
{
   
    bullet.setSize(Vector2f(5,5));
    bullet.setFillColor(Color::Green);

    bullet.setPosition(xPos + radius * cos(theta) + 23*cos(theta) , yPos + radius * sin(theta));
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

void Bullet::draw(RenderWindow &window){
    window.draw(bullet);
}

void Bullet::setPos(Vector2f newPos){
    bullet.setPosition(newPos);
}

int Bullet::getXPosition(){
    return bullet.getPosition().x;
}

int Bullet::getYPosition(){
    return bullet.getPosition().y;
}