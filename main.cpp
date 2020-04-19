#include <iostream>

using namespace std;

bool game_over = false;

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
}

void draw()
{

}

void input()
{

}

void logic()
{

}
