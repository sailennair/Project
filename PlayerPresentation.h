#ifndef PLAYERPRESENTATION_H
#define PLAYERPRESENTATION_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "GameWindow.h"
#include "PlayerPresentation.h"
#include "PlayerLogic.h"

#define PI 3.14159265

using namespace sf;

class PlayerPresentation {
    
public:

      PlayerPresentation(int xWindow, int yWindow);
   
      Sprite getPlayer();
    
    //This function will draw the player in the window.
       void draw(RenderWindow& window);
       void setPosition1( int xpos ,int ypos, float rotationAngle);
       int getXpos();
       int getYpos();
       int getXorigin();
       int getYorigin();
       int getRadius();
       int getXCentre();
       int getYCentre();
     //  void keyPressed(Event event);
      
      
private:

      int _xPosition;
      int _yPosition;
      int _xOrigin;
      int _yOrigin;
      int _theta;
      int _radius;
      int _xPos;
      int _yPos;
      int _xWindow;
      int _yWindow;
      int _xCentre;
      int _yCentre;
      
     // void move(int newxPos, int newyPos);
      
      
      Texture _playerSpaceshipTexture;
    
      Sprite _Player;
      




    
    
    
    
    
    
    
    
    };
    
    #endif