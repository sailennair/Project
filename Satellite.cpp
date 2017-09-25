#include "Satellite.h"

Satellite::Satellite(RenderWindow& window, int playerXpos, int playerYpos, float theta, int radius)
{
    // will take in the radius of the playerSprite
    _radius = radius * 0.4;
    _theta = theta;

    satellite.setSize(Vector2f(30, 30));
    satellite.setPosition(playerXpos - _radius * cos(_theta), playerYpos - _radius * sin(_theta));
    // satellite.setFillColor(Color::Blue);

    // satelliteSprite.setTextureRect(IntRect(0, 0, 30, 30));

    if(!satelliteTexture.loadFromFile("enemyShip.png")) {
        std::cerr << "Error Loading Player Texture";
    }
    satelliteTexture.setSmooth(true);
    satelliteSprite.setTexture(satelliteTexture);
    satelliteSprite.setPosition(satellite.getPosition());
    satelliteSprite.scale(0.3, 0.3);
}

void Satellite::draw(RenderWindow& window)
{
    // window.draw(satellite);
    window.draw(satelliteSprite);
}

void Satellite::updateMovement()
{

    satellite.rotate(10);
    satelliteSprite.setTexture(satelliteTexture);
   // satelliteSprite.scale(0.3, 0.3);
    satelliteSprite.rotate(10);
}

void Satellite::decreaseHealth(int damage)
{
    _health -= damage;
}

bool Satellite::isAlive()
{
    if(_health <= 0) {
        return false;
    } else {
        return true;
    }
}



int Satellite::getCentreX()
{
    _centreX = satellite.getPosition().x + (satellite.getSize().x / 2);
    return _centreX;
}

int Satellite::getCentreY()
{
    _centreY = satellite.getPosition().y + (satellite.getSize().y / 2);
    return _centreY;
}
