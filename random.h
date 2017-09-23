#ifndef RANDOM_H
#define RANDOM_H

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <cmath>
#include <time.h>

using namespace std;

int generateRandom(int max);
int generateRandom0(int max);
bool generateRandomBool();

#endif