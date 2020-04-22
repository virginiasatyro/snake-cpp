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
    _score = score;
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
    int snake_lenght = snake->getSnakeLenght();

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
            {
                bool print = false;
                for(int k = 0; k < snake_lenght; k++)
                {
                    int x_tail = snake->getXTail(k);
                    int y_tail = snake->getYTail(k);
                    if(x_tail == j && y_tail == i)
                    {
                        cout << SNAKE_BODY;
                        print = true;
                    }
                }
                if(!print)
                    cout << EMPTY_SPACE;
            }
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

        if(key == MOVE_LEFT)
            snake->setDirection(LEFT);
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
    int x_fruit = fruit->getX();
    int y_fruit = fruit->getY();
    int snake_length = snake->getSnakeLenght();
    Direction dir = snake->getDirection();

    // ------------------------------------------------
    int x_snake_prev = snake->getXTail(0);
    int y_snake_prev = snake->getYTail(0);
    int x2_snake_prev, y2_snake_prev;
    snake->setXTail(0, x_snake);
    snake->setYTail(0, y_snake);

    for(int i = 1; i < snake_length; i++)
    {
        x2_snake_prev = snake->getXTail(i);
        y2_snake_prev = snake->getYTail(i);
        snake->setXTail(i, x_snake_prev);
        snake->setYTail(i, y_snake_prev);
        x_snake_prev = x2_snake_prev;
        y_snake_prev = y2_snake_prev;
    }
    // ---

    // move
    snake->move(snake->getDirection());

    x_snake = snake->getX();
    y_snake = snake->getY();

    // checks if snake hit wall
    if(x_snake > WIDTH - 1 || x_snake < 0 || y_snake > HEIGHT - 1 || y_snake < 0)
        setGameOver(true);

    // checks if snake hits itself
    for(int i = 0; i < snake_length; i++)
    {
        int x_tail = snake->getXTail(i);
        int y_tail = snake->getYTail(i);
        if(x_tail == x_snake && y_tail == y_snake)
            setGameOver(true);
    }

    // snake get fruit
    if(x_snake == x_fruit && y_snake == y_fruit)
    {
        scoreUp();
        fruit->setX(rand() % WIDTH);
        fruit->setY(rand() % HEIGHT);
        snake->growSnake();
    }
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