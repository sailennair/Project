#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"

class projectile: public entity
{
public:
    int movementSpeed = 10;
    int attackDamage = 5;
    int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
    
    projectile();
    void update();
    //void updateMovement();
};


#endif