#include "PlayerPresentation.h"

PlayerPresentation::PlayerPresentation(int xWindow, int yWindow)
{

    _xPos = (xWindow / 2) - 20; // This is half of the x axis and - 20 because of the size of the sprite
    _yPos = yWindow - 70;       // -70 because of the sizie of sprite
    _theta = (PI) / 2;          // 270 degrees.
    _radius = _yPos / 2 - 20;
    _xWindow = xWindow;
    _yWindow = yWindow;
    _xOrigin = _xPos;
    _yOrigin = (yWindow / 2); //-40
                              //_yOrigin = _yPos;

    if(!_playerSpaceshipTexture.loadFromFile("player.PNG")) {
        std::cerr << "Error Loading Player Texture";
    }
    _playerSpaceshipTexture.setSmooth(true);
    _Player.setTexture(_playerSpaceshipTexture);
    _Player.setScale(Vector2f(0.1, 0.1));
    _Player.setPosition(_xPos, _yPos);
    _Player.setOrigin(23, 0);
}

void PlayerPresentation::draw(RenderWindow& window)
{
    window.draw(_Player);
}

Sprite PlayerPresentation::getPlayer()
{
    return _Player;
}

void PlayerPresentation::setPosition1(int xpos, int ypos, float rotationAngle)
{
    _Player.setPosition(_xOrigin + xpos, _yOrigin + ypos);
    _Player.rotate(rotationAngle);
}

int PlayerPresentation::getXpos()
{
    return _Player.getPosition().x;
}

int PlayerPresentation::getYpos()
{
    return _Player.getPosition().y;
}

int PlayerPresentation::getXorigin()
{
    return _xOrigin;
}

int PlayerPresentation::getYorigin()
{
    return _yOrigin;
}

int PlayerPresentation::getRadius()
{
    return _radius;
}

int PlayerPresentation::getXCentre()
{
    return _Player.getOrigin().x;
}

int PlayerPresentation::getYCentre()
{
    return _Player.getOrigin().y;
}