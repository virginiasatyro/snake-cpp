    
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

void Snake::setXTail(int n, int value)
{
    _x_tail[n] = value;
}

void Snake::setYTail(int n, int value)
{
    _y_tail[n] = value;
}

void Snake::setSnakeLenght(int lenght)
{
    _snake_length = lenght;
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

int Snake::getXTail(int n)
{
    return _x_tail[n];
}

int Snake::getYTail(int n)
{
    return _y_tail[n];
}

int Snake::getSnakeLenght()
{
    return _snake_length;
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

void Snake::growSnake()
{
    setSnakeLenght(getSnakeLenght() + 1);
}