/***********************************************************************************
 * File: game.h
 * C++
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on April 2020 
 * 
 * Defining the snake class.
 ***********************************************************************************/

#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "snake.h"
#include "fruit.h"
#include "input.h"

using namespace std;

#define WIDTH  20
#define HEIGHT 20

// define moving keys
const char MOVE_LEFT  = 'A';
const char MOVE_RIGHT = 'D';
const char MOVE_UP    = 'W';
const char MOVE_DOWN  = 'S';
const char QUIT = 'Q';

// define bricks
#define WALL_TOP    "▄"
#define WALL_BOTTOM "▀"
#define WALL_LEFT   "▋"
#define WALL_RIGHT  "▐"
#define EMPTY_SPACE " "

class Game
{
private:
    int _width;      // game width
    int _height;     // game height
    int _score;      // score of player
    bool _game_over; //
    bool _quit;      // quit game 

    Snake *snake;
    Fruit *fruit;

public:
    Game(); // constructor
    ~Game(); // destructor 

    // set functions 
    void setWidth(int);
    void setHeight(int);
    void setScore(int);
    void setGameOver(bool);
    void setQuit(bool);

    // get functions 
    int getWidth();
    int getHeight();
    int getScore();
    bool getGameOver();
    bool getQuit();

    // scores 
    void scoreUp();

    // draw functions
    void draw();

    // input functions 
    void input();

    // logic of game 
    void logic();

    // run game 
    void run();
};

#endif // GAME_H
