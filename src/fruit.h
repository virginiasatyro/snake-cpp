/***********************************************************************************
 * File: fruit.h
 * C++
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on April 2020 
 * 
 * Defining the fruit class.
 ***********************************************************************************/

#ifndef FRUIT_H
#define FRUIT_H

#include <iostream>

#define FRUIT "✽"

class Fruit
{
private:
    int _x;
    int _y;

public:
    Fruit(int, int); // contructor
    ~Fruit(); // destructor 

    // set functions 
    void setX(int);
    void setY(int);

    // get functions 
    int getX();
    int getY();
};

#endif // FRUIT_H