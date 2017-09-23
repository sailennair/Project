#include "Enemy.h"

Enemy::Enemy(RenderWindow& window, int playerXpos, int playerYpos, float theta)
{
    _enemy.setSize(Vector2f(30, 30));
    _enemy.setFillColor(Color::Red);
    _enemy.setPosition((window.getSize().x) / 2, (window.getSize().y) / 2);

    // srand(time(NULL));
    _theta = theta;
    //_theta = (theta*180)/PI + 270;
    //    if (_theta > 360){
    //        _theta -= 270;
    //    }
    //
    //    if(playerXpos < (window.getSize().x)/2 && playerYpos < (window.getSize().y)/2) {
    //        _xsign = -1;
    //        _ysign = 1;
    //        std:: cout << 1 << endl;
    //    }
    //
    //    if(playerXpos > (window.getSize().x)/2 && playerYpos < (window.getSize().y)/2) {
    //        _xsign = 1;
    //        _ysign = 1;
    //        std::cout << 2 << endl;
    //    }
    //
    //    if(playerXpos < (window.getSize().x)/2 && playerYpos > (window.getSize().y)/2) {
    //        _xsign = -1;
    //        _ysign = -1;
    //        std:: cout << 3 <<endl;
    //    }
    //
    //    if(playerXpos > (window.getSize().x)/2 && playerYpos > (window.getSize().y)/2) {
    //        _xsign = 1;
    //        _ysign = -1;
    //        std:: cout <<4 << endl;
    //    }
    //
    //

    _xpos = _enemy.getPosition().x;

    _ypos = _enemy.getPosition().y;

   // std::cout << theta << "   " << _xsign << "   " << _ysign << endl;
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
