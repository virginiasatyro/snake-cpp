/***********************************************************************************
 * File: snake.h
 * C++
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on April 2020 
 * 
 * Defining the snake class.
 ***********************************************************************************/

#ifndef SNAKE_H
#define SNAKE_H

#define SNAKE_MAX 100

#define SNAKE_HEAD "●"
#define SNAKE_BODY "•"

enum Direction {STOP = 0, LEFT, RIGHT, UP, DOWN};

class Snake
{
private:
    int _x;
    int _y;

    Direction _direction;

public: 
    Snake(int, int);  // constructor 
    ~Snake(); // destructor

    // set functions 
    void setX(int);
    void setY(int);
    void setDirection(Direction);

    // get functions 
    int getX();
    int getY();
    Direction getDirection();

    void move(Direction);
};

#endif // SNAKE_H