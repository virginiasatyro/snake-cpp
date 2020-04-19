    
/***********************************************************************************
 * File: snake.cpp
 * C++
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on April 2020 
 * 
 * Defining the snake class.
 ***********************************************************************************/

#include "snake.h"

// constructor 
Snake::Snake(int x, int y)
{
    setDirection(STOP);

    setX(x);
    setY(y);
}

// destructor
Snake::~Snake()
{
    // 
}

// set functions 
void Snake::setX(int x)
{
    _x = x;
}

void Snake::setY(int y)
{
    _y = y;
}

void Snake::setDirection(Direction d)
{
    _direction = d;
}

// get functions 
int Snake::getX()
{
    return _x;
}

int Snake::getY()
{
    return _y;    
}

Direction Snake::getDirection()
{
    return _direction;
}

void Snake::move(Direction dir)
{
    switch (dir)
    {
    case LEFT:
        setX(getX() - 1);
        break;
    case RIGHT:
        setX(getX() + 1);
        break;
    case UP:
        setY(getY() - 1);
        break;
    case DOWN:
        setY(getY() + 1);
        break;
    default:
        break;
    }
}