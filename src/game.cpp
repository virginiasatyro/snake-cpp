/***********************************************************************************
 * File: game.cpp
 * C++
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on April 2020 
 * 
 * Defining the game class.
 ***********************************************************************************/

#include "game.h"

// constructor
Game::Game()
{
    setGameOver(false);
    
    snake = new Snake(WIDTH/2, HEIGHT/2);
    fruit = new Fruit(WIDTH, HEIGHT);

    setQuit(false);
    setScore(0);
    setWidth(WIDTH);
    setHeight(HEIGHT);
}

// destructor 
Game::~Game()
{
    delete snake;
}

// set functions 
void Game::setWidth(int width)
{
    _width = width;
}

void Game::setHeight(int height)
{
    _height = height;
}

void Game::setScore(int score)
{
    _score = 0;
}

void Game::setGameOver(bool game_over)
{
    _game_over = game_over;
}

void Game::setQuit(bool quit)
{
    _quit = quit;
}

// get functions 
int Game::getWidth()
{
    return _width;
}

int Game::getHeight()
{
    return _height;
}

int Game::getScore()
{
    return _score;
}

bool Game::getGameOver()
{
    return _game_over;
}

bool Game::getQuit()
{
    return _quit;
}

// scores 
void Game::scoreUp()
{
    setScore(getScore() + 10);
}

// draw functions
void Game::draw()
{
    // auxiliar variables
    int x_snake = snake->getX();
    int y_snake = snake->getY();
    int x_fruit = fruit->getX();
    int y_fruit = fruit->getY();

    system("clear");

    for(int i = 0; i < getWidth() + 2; i++) // top wall
        cout << WALL_TOP;
    cout << endl;

    for(int i = 0; i < getHeight(); i++) // print walls on the side
    {
        for(int j = 0; j < getWidth(); j++)
        {
            if(j == 0)
                cout << WALL_LEFT;
            if(i == y_snake && j == x_snake)
                cout << SNAKE_HEAD;
            else if(i == y_fruit && j == x_fruit)
                cout << FRUIT;
            else 
                cout << EMPTY_SPACE;
            if(j == getWidth() - 1)
                cout << WALL_RIGHT;
        }
        cout << endl;
    }

    for(int i = 0; i < getWidth() + 2; i++)
        cout << WALL_BOTTOM;
    cout << endl;

    cout << "SCORE: " << getScore() << endl;
}

// input functions 
void Game::input()
{
    if(_kbhit())
    {
        char key = getchar();
        key = toupper(key);

        if(key == MOVE_LEFT){
            snake->setDirection(LEFT);
        }
        else if(key == MOVE_RIGHT)
            snake->setDirection(RIGHT);
        else if(key == MOVE_UP)
            snake->setDirection(UP);
        else if(key == MOVE_DOWN)
            snake->setDirection(DOWN);
        else if(key == QUIT)
            setQuit(true); 
    }
}

// logic of game 
void Game::logic()
{
    // auxiliar variables
    int x_snake = snake->getX();
    int y_snake = snake->getY();
    Direction dir = snake->getDirection();

    snake->move(snake->getDirection());
}

// run game 
void Game::run()
{
    while (!getGameOver() && !getQuit())
    {
        draw();
        input();
        logic();
        usleep(80000);
    }
}