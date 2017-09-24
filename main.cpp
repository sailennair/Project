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
#include "EnemyBullet.h"
#include "Satellite.h"

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

    std::vector<Enemy> enemyVec;

    std::vector<Bullet> bulletVec;

    std::vector<Satellite> satelliteVec;

    bool isFiring = false;
    int createEnemyNumber = 0;
    int timer;
    int enemyOutOfBounds = 0;
    int counter = 0;
    int counter2 = 0;
    bool isEnemyFiring = false;
    int newGunCount = 0;
    int gunType = 1;

    vector<EnemyBullet> enemyBulletVec;

    while(window.isOpen()) {

        // sf::Event event;
        // std::cout << playerSprite.getXpos()<<"  "<< playerSprite.getYpos()<<endl;
        sf::Event event;
        while(window.pollEvent(event)) {

            // Checking movement and if a bullet is fired using keyStrokes
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
        /////////////////////////////////////////////////////////////////////////////////

        // Creatign a random variable used for generating the enemies and satellites
        timer = timer + 1;
        // Generating the enemy, creating 10 of them all equal time apart. they will be set off in the direction of the
        // player at the moment it was created

        if(createEnemyNumber < 10) {
            if(timer % 50 == 0) {
                Enemy enemy(window, playerSprite.getXpos(), playerSprite.getYpos(), spriteLogic.getTheta());
                enemyVec.push_back(enemy);
                createEnemyNumber++;
            }
        }
        ///////////////////////////////////////////////////////////////////////////////////////
        // Generatign the Satellites, generating three at once. Need to make them not have a time lifespan , but rather
        // only die when shot. Will use a bool to check this
        if(satelliteVec.size() == 0) {
            if(timer % 500 == 0) {
                for(int w = 0; w < 3; w++) {
                    Satellite satellite(window, playerSprite.getXpos() + 30 * w, playerSprite.getYpos() + 30 * w,
                        spriteLogic.getTheta(), spriteLogic.getRadius());
                    satelliteVec.push_back(satellite);
                }
            }
        }

        window.clear(sf::Color::Black);
        // Firing the bullet from the player sprite and changes gun when three satelittes have been killed
        if(isFiring == true) {
            if(newGunCount > 0 && newGunCount % 3 == 0) {
                gunType = 2;
            }
            Bullet newBullet(playerSprite.getXorigin(), playerSprite.getYorigin(), spriteLogic.getTheta(),
                playerSprite.getRadius(), gunType);

            bulletVec.push_back(newBullet);
            isFiring = false;
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////////////

        // Collision detection for playerBullet and enemy
        counter = 0;
        for(auto iter = bulletVec.begin(); iter != bulletVec.end(); iter++) {
            counter2 = 0;
            //            if(bulletVec.size() == 0) {
            //                break;
            //            }
            for(auto iter4 = enemyVec.begin(); iter4 != enemyVec.end(); iter4++) {
                //                if(bulletVec.size() == 0) {
                //                    break;
                //                }
                if(bulletVec[counter].bullet.getGlobalBounds().intersects(
                       enemyVec[counter2]._enemy.getGlobalBounds())) {
                    enemyVec[counter2].decreaseHealth(bulletVec[counter].getDamage());
                    // bulletVec.erase(bulletVec.begin() + counter);
                    bulletVec[counter].bullet.setFillColor(Color::Black);
                   
                    if(bulletVec[counter].getDamage() > 0) {
                        cout << "collision" << endl;
                    }
                     bulletVec[counter].setDamage(0);
                }

                counter2++;
            }

            counter++;
        }
        ////////////////////////////////////////////////////////////////////////////////////

        // Collision detection for Satellites
        // Collision detection for playerBullet and enemy
        counter = 0;
        for(auto iter = bulletVec.begin(); iter != bulletVec.end(); iter++) {
            //            if(bulletVec.size() == 0){
            //                    break;
            //                }
            counter2 = 0;
            for(auto iter4 = satelliteVec.begin(); iter4 != satelliteVec.end(); iter4++) {
                //                if(bulletVec.size() == 0){
                //                    break;
                //                }
                if(bulletVec[counter].bullet.getGlobalBounds().intersects(
                       satelliteVec[counter2].satellite.getGlobalBounds())) {

                    satelliteVec[counter2].decreaseHealth(bulletVec[counter].getDamage());
                    //  bulletVec.erase(bulletVec.begin() +counter);
                    bulletVec[counter].bullet.setFillColor(Color::Black);
                    bulletVec[counter].setDamage(0);
                }

                counter2++;
            }

            counter++;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        // Deleting the bullet object once it reaches a small area at the centre of the window, if it is not at that
        // point then it will just draw the bullet and move it a little bit
        for(auto i = 0; i < bulletVec.size(); i++) {

            if((bulletVec[i].getXPosition() < ((window.getSize().x / 2) + 20)) &&
                (bulletVec[i].getXPosition() > ((window.getSize().x / 2) - 20)) &&
                (bulletVec[i].getYPosition() > ((window.getSize().y / 2) - 20)) &&
                (bulletVec[i].getYPosition() < ((window.getSize().y / 2) + 20))) {
                bulletVec.erase(bulletVec.begin() + i);
            }

            bulletVec[i].draw(window);

            bulletVec[i].fire(window);
        }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////

        // EnemyOutOfBounds checks if all the enemies are out of the visible window, if all are out of the visible
        // window, then they will reappear from the centre again. This section also shows the deletion of an enemy
        // object once its health has reached zero
        enemyOutOfBounds = 0;

        for(auto i = 0; i < enemyVec.size(); i++) {
            if((enemyVec[i].getXPosition() < 0) || (enemyVec[i].getXPosition() > ((window.getSize().x))) ||
                (enemyVec[i].getYPosition() > ((window.getSize().y))) || (enemyVec[i].getYPosition() < 0)) {

                enemyOutOfBounds++;
            }

            if(enemyOutOfBounds == enemyVec.size()) {

                for(auto k = 0; k < enemyVec.size(); k++) {
                    enemyVec[i].centreEntity(spriteLogic.getTheta());
                }
            }

            if(enemyVec[i].isAlive() == false) {
                enemyVec.erase(enemyVec.begin() + i);
                cout << "Enemy Dead" << endl;
            }

            enemyVec[i].draw(window);

            enemyVec[i].moveIncrement();
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////

        // The program will check if there are any satellites on the scree, if there is then they will be drawn and the
        // deletion of them will occure if their health reahces 0, once 3 satelliets have been killed, the gun will
        // upgrade howver this is doen in the bullet class
        if(satelliteVec.size() > 0) {
            for(auto v = 0; v < satelliteVec.size(); v++) {

                satelliteVec[v].draw(window);
                satelliteVec[v].updateMovement();

                if(satelliteVec[v].isAlive() == false) {
                    satelliteVec.erase(satelliteVec.begin() + v);
                    newGunCount++;
                }
            }
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////

        playerSprite.draw(window);

        window.display();
    }

    cout << enemyVec.size() << endl;

    return 0;
}

// Testing to see if Sailens branch is really working or not.