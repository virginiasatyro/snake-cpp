/***********************************************************************************
 * File: fruit.cpp
 * C++
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on April 2020 
 * 
 * Defining the snake class.
 ***********************************************************************************/

#include "fruit.h"

// contructor
Fruit::Fruit(int width, int height)
{
    srand(time(NULL));

    setX(rand() % width);
    setY(rand() % height);
}

// destructor 
Fruit::~Fruit()
{
    // 
}

// set functions 
void Fruit::setX(int x)
{
    _x = x;
}

void Fruit::setY(int y)
{
    _y = y;
}

// get functions 
int Fruit::getX()
{
    return _x;
}

int Fruit::getY()
{
    return _y;
}