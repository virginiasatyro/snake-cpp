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
    srand(time(NULL));

    setGameOver(false);
    
    snake = new Snake();

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

    system("clear");

    for(int i = 0; i < getWidth() + 1; i++) // top wall
        cout << WALL_TOP;
    cout << endl;

    for(int i = 0; i < getHeight(); i++)
    {
        for(int j = 0; j < getWidth(); j++)
        {
            if(j == 0)
                cout << WALL_LEFT;
            else 
                cout << EMPTY_SPACE;
            if(j == getWidth() - 1)
                cout << WALL_RIGHT;
        }
        cout << endl;
    }

    for(int i = 0; i < getWidth() + 1; i++)
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

        switch (key)
        {
        case MOVE_LEFT:
            snake->setDirection(LEFT);
            break;
        case MOVE_RIGHT:
            snake->setDirection(RIGHT);
            break;
        case MOVE_UP:
            snake->setDirection(UP);
            break;
        case MOVE_DOWN:
            snake->setDirection(DOWN);
            break;
        case QUIT:
            setGameOver(true);
            break;
        default:
            break;
        }
    }
}

// logic of game 
void Game::logic()
{
    int x_snake = snake->getX();
    int y_snake = snake->getY();

    switch (snake->getDirection())
    {
    case LEFT:
        snake->setX(x_snake--);
        break;
    case RIGHT:
        snake->setX(x_snake++);
        break;
    case UP:
        snake->setY(y_snake--);
        break;
    case DOWN:
        snake->setY(y_snake++);
        break;
    default:
        break;
    }
}

// run game 
void Game::run()
{
    while (!getGameOver())
    {
        draw();
        input();
        logic();
        usleep(100000);
    }
}