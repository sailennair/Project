#include "Satellite.h"

Satellite::Satellite(RenderWindow& window, int playerXpos, int playerYpos, float theta, int radius)
{
    // will take in the radius of the playerSprite
    _radius = radius * 0.4;
    _theta = theta;

    satellite.setSize(Vector2f(30, 30));
    satellite.setFillColor(Color::Blue);

    satellite.setPosition(playerXpos - _radius * cos(_theta), playerYpos - _radius * sin(_theta));
}

void Satellite::draw(RenderWindow& window)
{
    window.draw(satellite);
}

void Satellite::updateMovement()
{

    // satellite.move((_radius)*cos(_theta),(_radius)*sin(_theta));
    satellite.rotate(10);
}

void Satellite::decreaseHealth(int damage)
{
    _health -= damage;
}

bool Satellite::isAlive()
{
    if(_health <= 0) {
        return  false;
    } else {
        return  true;
    }
}
