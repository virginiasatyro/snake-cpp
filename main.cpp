#include <iostream>

#include "input.h"

using namespace std;

bool game_over = false;
const int width = 20;
const int height = 20;
int x, y;
int x_fruit, y_fruit;
int score;
enum Direction{STOP = 0, LEFT, RIGHT, UP, DOWN};
Direction direction;

void setup();
void draw();
void input();
void logic();

int main()
{
    setup();
    while (!game_over)
    {
        draw();
        input();
        logic();
        // sleep
        usleep(80000);
    }
    
    return 0;
}

void setup()
{
    game_over = false;
    direction = STOP;

    x = width / 2; // snake in the middle
    y = height / 2;

    x_fruit = rand() % width;
    y_fruit = rand() % height;
}

void draw()
{
    system("clear"); // clear console
    
    for(int i = 0; i < width + 1; i++) // top wall
        cout << "#";
    cout << endl;

    for(int i = 0; i < height; i++) // print lateral walls ans the in between 
    {
        for(int j = 0; j < width; j++)
        {
            if(j == 0 || j == width - 1)
                cout << "#";
            if(i == y && j == x) 
                cout << "O"; // head
            else if(i == y_fruit && j == x_fruit)
                cout << "*";
            else 
                cout << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < width + 1; i++) //  bottom wall
        cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;
}

void input()
{
    if(_kbhit())
    {
        switch (getchar())
        {
        case 'a':
            direction = LEFT;
            break;
        case 'd':
            direction = RIGHT;
            break;
        case 'w':
            direction = UP;
            break;
        case 's':
            direction = DOWN;
            break;     
        case 'q':
            game_over = true;
            break;   
        default:
            break;
        }
    }
}

void logic()
{
    switch (direction)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;  
    default:
        break;
    }

    if(x > width || x < 0 || y > height || y < 0)
        game_over = true;

    if(x == x_fruit && y == y_fruit)
    {
        score += 10;
        x_fruit = rand() % width;
        y_fruit = rand() % height;
    }
}
