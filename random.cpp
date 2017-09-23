#include "random.h"

int generateRandom(int max)
{
    //srand(time(NULL));
//    int randomNumber = rand();
//    float random = (randomNumber % max) + 1;
//    int myRandom = random;
    
    return 1+ (rand() % max);
}

int generateRandom0(int max)
{
    srand(time(NULL));
    int randomNumber = rand();
    float random = (randomNumber % max);
    int myRandom = random;
    return myRandom;
}

bool generateRandomBool()
{
    int randomNumber = rand();
    float random = (randomNumber % 2) + 1;
    int myRandom = random;
    if (myRandom == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}