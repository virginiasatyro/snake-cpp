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
#define SNAKE_BODY "⚈"

enum Direction {STOP = 0, LEFT, RIGHT, UP, DOWN};

class Snake
{
private:
    int _x; // x position of snake head
    int _y; // y position of snake head
    int _x_tail[SNAKE_MAX]; // x snake tail
    int _y_tail[SNAKE_MAX]; // y snake tail
    int _snake_length;

    Direction _direction;

public: 
    Snake(int, int);  // constructor 
    ~Snake(); // destructor

    // set functions 
    void setX(int);
    void setY(int);
    void setXTail(int, int);
    void setYTail(int, int);
    void setSnakeLenght(int);
    void setDirection(Direction);

    // get functions 
    int getX();
    int getY();
    int getXTail(int);
    int getYTail(int);
    int getSnakeLenght();
    Direction getDirection();

    void move(Direction);
    void growSnake();
};

#endif // SNAKE_H