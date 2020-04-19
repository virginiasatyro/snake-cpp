#include <iostream>

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
    
    for(int i = 0; i < width; i++) // top wall
        cout << "#";
    cout << endl;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(j == 0 || j == width - 1)
                cout << "#";
            else 
                cout << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < width; i++) //  bottom wall
        cout << "#";
    cout << endl;
}

void input()
{

}

void logic()
{

}
