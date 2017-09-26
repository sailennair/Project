#include "PlayerLogic.h"
#include "Satellite.h"
#include "Enemy.h"
#include "Bullet.h"
#include "EnemyBullet.h"
#include "GameWindow.h"
#include "PlayerPresentation.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#define PI 3.14159265

// Testing for "PlayerPresentation.h"
TEST_CASE("XposReturnsCorrectPlayerPosition")
{
    PlayerPresentation player(100, 100);
    auto x = player.getXpos();

    CHECK(x == 30);
}

TEST_CASE("YposReturnsCorrectPlayerPosition")
{
    PlayerPresentation player(100, 100);
    auto x = player.getYpos();

    CHECK(x == 30);
}

TEST_CASE("RadiusofPlayerMovementisCorrect")
{
    PlayerPresentation player(200, 200);
    auto x = player.getRadius();

    CHECK(x == 45);
}

TEST_CASE("locationofSpriteOrigin")
{
    PlayerPresentation player(200, 200);
    auto x = player.getXorigin();
    CHECK(x == 80);
    auto y = player.getYorigin();
    CHECK(y == 100);
}

// Testing for "PlayerLogic.h"
TEST_CASE("ReturnsCorrectAngle")
{
    PlayerLogic playerLogic(200, 200);
    auto x = playerLogic.getTheta();
    CHECK(x > 1.5706);
    CHECK(x < 1.5708);
}

TEST_CASE("CheckPlayerHealthDecreases")
{
    PlayerLogic playerLogic(200, 200);
    playerLogic.reduceHealth(50);
    auto x = playerLogic.getHealth();
    CHECK(x == 50);
}

TEST_CASE("CheckPlayerDiesWhenHealthis0")
{
    PlayerLogic playerLogic(200, 200);
    auto x = playerLogic.getHealth();
    CHECK(x == 100);
    playerLogic.reduceHealth(100);
    CHECK(playerLogic.isAlive() == false);
}

// Tests for "Satellite.h"
TEST_CASE("SatelliteHealthDecreases")
{
    GameWindow gamewindow(600, 600);
    sf::RenderWindow window(sf::VideoMode(gamewindow.getXWindow(), gamewindow.getYWindow()), "My Window");
    Satellite satellite(window, 200, 200, 2.2024f, 40);
    satellite.decreaseHealth(10);
    auto x = satellite.getHealth();
    CHECK(x == 35);
}

TEST_CASE("SatellietDiesWhenHealthis0")
{
    GameWindow gamewindow(600, 600);
    sf::RenderWindow window(sf::VideoMode(gamewindow.getXWindow(), gamewindow.getYWindow()), "My Window");
    Satellite satellite(window, 200, 200, 2.2024f, 40);
    satellite.decreaseHealth(45);
    auto x = satellite.getHealth();
    CHECK(x == 0);
    CHECK(satellite.isAlive() == false);
}

// Tests for "Enemy.h"
TEST_CASE("EnemyXPositionReturnsCorrectly")
{
    GameWindow gamewindow(600, 600);
    sf::RenderWindow window(sf::VideoMode(gamewindow.getXWindow(), gamewindow.getYWindow()), "My Window");
    Enemy enemy(window, 200, 200, 2.1f);
    auto x = enemy.getXPosition();
    CHECK(x == 300);
}

TEST_CASE("EnemyYPositionReturnsCorrectly")
{
    GameWindow gamewindow(600, 600);
    sf::RenderWindow window(sf::VideoMode(gamewindow.getXWindow(), gamewindow.getYWindow()), "My Window");
    Enemy enemy(window, 200, 200, 2.1f);
    auto y = enemy.getYPosition();
    CHECK(y == 300);
}

TEST_CASE("EnemyHealthReturnsCorrectly")
{
    GameWindow gamewindow(600, 600);
    sf::RenderWindow window(sf::VideoMode(gamewindow.getXWindow(), gamewindow.getYWindow()), "My Window");
    Enemy enemy(window, 200, 200, 2.1f);
    auto x = enemy.getHealth();
    CHECK(x == 45);
}

TEST_CASE("EnemyHealthdecreasesCorrectly")
{
    GameWindow gamewindow(600, 600);
    sf::RenderWindow window(sf::VideoMode(gamewindow.getXWindow(), gamewindow.getYWindow()), "My Window");
    Enemy enemy(window, 200, 200, 2.1f);
    enemy.decreaseHealth(20);
    auto x = enemy.getHealth();
    CHECK(x == 25);
}

TEST_CASE("EnemyHealthDiesWHenHealthIs0")
{
    GameWindow gamewindow(600, 600);
    sf::RenderWindow window(sf::VideoMode(gamewindow.getXWindow(), gamewindow.getYWindow()), "My Window");
    Enemy enemy(window, 200, 200, 2.1f);
    enemy.decreaseHealth(45);

    CHECK(enemy.isAlive() == false);
}

// Tests for "bullet.h"

TEST_CASE("CheckCorrectXPositionIsReturned")
{
    Bullet bullet(100, 100, 1.2f, 5, 1);
    auto x = bullet.getXPosition();
    CHECK(x == 122);
}

TEST_CASE("CheckCorrectYPositionIsReturned")
{
    Bullet bullet(100, 100, 1.2f, 5, 1);
    auto x = bullet.getYPosition();
    CHECK(x == 91);
}

TEST_CASE("DamageCanBeCorrectlyChanged")
{
    Bullet bullet(100, 100, 1.2f, 5, 1);
    bullet.setDamage(20);
    auto x = bullet.getDamage();
    CHECK(x == 20);
}

// Tests for "EnemyBullet.h"
TEST_CASE("CheckCorrectXPositionIsReturned")
{
    EnemyBullet bullet(100, 100, 1.2f);
    auto x = bullet.getXPosition();
    CHECK(x == 100);
}

TEST_CASE("CheckCorrectYPositionIsReturned")
{
    EnemyBullet bullet(100, 100, 1.2f);
    auto x = bullet.getYPosition();
    CHECK(x == 100);
}

TEST_CASE("CorrectDamageIsReturened")
{
    EnemyBullet bullet(100, 100, 1.2f);
    auto x = bullet.getDamage();
    CHECK(x == 5);
}

TEST_CASE("DamgeChangesCorrectly")
{
    EnemyBullet bullet(100, 100, 1.2f);
    bullet.setDamage(0);
    auto x = bullet.getDamage();
    CHECK(x == 0);
}
