#include <stdio.h>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include "PlayerPresentation.h"
#include "PlayerLogic.h"
#include "Bullet.h"
#include "Enemy.h"
#include <vector>
#include <time.h>

using namespace std;

int main(int argc, char** argv)
{
    // sf::RenderWindow window(sf::VideoMode(800,600), "My Window");

    //    window.setVerticalSyncEnabled(true);

    GameWindow gameWindow(1000, 700);

    int xWindow = gameWindow.getXWindow();
    int yWindow = gameWindow.getYWindow();

    sf::RenderWindow window(sf::VideoMode(xWindow, yWindow), "My Window");

    window.setVerticalSyncEnabled(true);

    PlayerPresentation playerSprite(xWindow, yWindow);
    PlayerLogic spriteLogic(xWindow, yWindow);
    Sprite actualSprite = playerSprite.getPlayer();

    // Enemy enemy(Vector2f(50, 50));
    std::vector<Enemy> enemyVec;
    std::vector<Bullet> bulletVec;
    bool isFiring = false;
    int createEnemyNumber = 0;
    // enemy.setPos(Vector2f(xWindow/2-25,yWindow/2-25));

    while(window.isOpen()) {

        // sf::Event event;
        // std::cout << playerSprite.getXpos()<<"  "<< playerSprite.getYpos()<<endl;
        sf::Event event;
        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed) {
                window.close();
                break;
            }
            if(event.key.code == Keyboard::D) {
                int newxPos = spriteLogic.moveLeftX();
                int newyPos = spriteLogic.moveLeftY();
                float angle = -4;
                playerSprite.setPosition1(newxPos, newyPos, angle);
                //                            std::cout << newxPos << "  " << newyPos << endl;
                //                            std::cout << playerSprite.getXpos()<<endl;
            }

            if(event.key.code == Keyboard::A) {
                int newxPos = spriteLogic.moveRightX();
                int newyPos = spriteLogic.moveRightY();
                float angle = 4;
                playerSprite.setPosition1(newxPos, newyPos, angle);
                // std::cout << newxPos << "  " << newyPos << endl;
            }

            if(Keyboard::isKeyPressed(Keyboard::Space)) {
                isFiring = true;
            }
        }

        createEnemyNumber = createEnemyNumber + 1;
        if(createEnemyNumber % 50 == 0) {
            Enemy enemy(window, playerSprite.getXpos(), playerSprite.getYpos(), spriteLogic.getTheta());
            enemyVec.push_back(enemy);
        }

        // std::cout << createEnemyNumber << endl;

        window.clear(sf::Color::Black);

        if(isFiring == true) {
            Bullet newBullet(
                playerSprite.getXorigin(), playerSprite.getYorigin(), spriteLogic.getTheta(), playerSprite.getRadius());

            bulletVec.push_back(newBullet);
            isFiring = false;
            // std::cout << spriteLogic.getRadius() << "     " << playerSprite.getRadius() << endl;
        }

        for(auto i = 0 ; i < bulletVec.size(); i++) {

            if((bulletVec[i].getXPosition() < ((window.getSize().x / 2) + 20)) &&
                (bulletVec[i].getXPosition() > ((window.getSize().x / 2) - 20)) &&
                (bulletVec[i].getYPosition() > ((window.getSize().y / 2) - 20)) &&
                (bulletVec[i].getYPosition() < ((window.getSize().y / 2) + 20))) {
                bulletVec.erase( bulletVec.begin() + i);
            }
            bulletVec[i].draw(window);
            bulletVec[i].fire(window);
        }

        for(auto i = 0; i < enemyVec.size(); i++) {
            if((enemyVec[i].getXPosition() < 0) || (enemyVec[i].getXPosition() > ((window.getSize().x))) ||
                (enemyVec[i].getYPosition() > ((window.getSize().y))) || (enemyVec[i].getYPosition() < 0)) {
                enemyVec.erase(enemyVec.begin() + i);
            }
            enemyVec[i].draw(window);
            enemyVec[i].moveIncrement();
        } 

        playerSprite.draw(window);

        window.display();
    }

    cout << enemyVec.size() << endl;

    return 0;
}
// - 30*cos(spriteLogic.getTheta())
//-10*sin(spriteLogic.getTheta())