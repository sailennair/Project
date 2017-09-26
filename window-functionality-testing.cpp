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
#include "IntroductionWindow.h"


#include "FinalWindow.h"

using namespace sf;

int main(){
    
    // This is the order to excecute The Final window class.
    
    FinalWindow window(800, 600); // Initializing a Final Window
    // If the Player lost the game
    window.setPLayerLostGame(true); // if the player won pass fals
    
    // The run function handles the logic
    window.run();
    
    // Then querry if the player chose to continue by using
    // window.isPlayerQuittingGame()
    // Then make the appropiate action on main
    
    
    
    return 0;
}