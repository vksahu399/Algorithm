#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

bool gameOver;
unsigned long speed_snake;
const int height = 20, width = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int ntail;
enum eDirection{STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir, prevdir;

void Setup()
{
    speed_snake = 60;
    srand(time(0));
    ntail = 0;
    gameOver = false;
    dir = STOP;
    prevdir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % (width - 2);
    fruitY = rand() % (height - 2);
    score = 0;
}

void Draw()
{
    system("cls");
    for(int i = 0; i<width+1; i++)
        cout << '#';
    cout << endl;
    for(int i = 0; i < height ; i++)
    {
        for(int j = 0; j < width ; j++)
        {
            if(j == 0 || j == width-1)
                cout << '#';
            if(x == j && y == i)
                cout << 'O';
            else if(fruitX == j && fruitY == i)
                cout << 'f';
            else
            {
            	bool print = false;
            	for(int k = 0; k < ntail; k++)
            	{
            		if(tailX[k] == j && tailY[k] == i)
            		{
            			print = true;
            			cout << "o";
					}
				}
				if(!print)
                	cout << ' ';
    		}
        }
        cout << endl;
    }
    for(int i = 0 ; i  < width+1 ; i++)
        cout << '#';
    cout << "\nScore: " << score << endl;
}

void Input()
{
    if(_kbhit())
        {
            switch(_getch())
            {
                case 'a':
                    dir = LEFT;
                    break;
                case 'd':
                    dir = RIGHT;
                    break;
                case 's':
                    dir = DOWN;
                    break;
                case 'w':
                    dir = UP;
                    break;
                case 'x':
                    gameOver = true;
                	break;
            }
        }
}

void Logic()
{

	for(int i = ntail ; i > 0; i--)
		{
			tailX[i]=tailX[i-1];
			tailY[i]=tailY[i-1];
		}
	tailX[0] = x;
	tailY[0] = y;
    switch(dir)
    {
        case LEFT:
        	if(prevdir == RIGHT && ntail > 0)
        	{
        		dir = prevdir; x++; break;
			}
            x--; break;
        case RIGHT:
        	if(prevdir == LEFT && ntail > 0)
        	{
        		dir = prevdir; x--; break;
			}
            x++; break;
        case UP:
        	if(prevdir == DOWN && ntail > 0)
        	{
        		dir = prevdir; y++; break;
			}
            y--; break;
        case DOWN:
        	if(prevdir == UP && ntail > 0)
        	{
        		dir = prevdir; y--; break;
			}
            y++; break;
    }
    if(x > width-3) x = 0;
    else if(x < 0) x = width-2;
    else if(y < 0) y = height;
    else if(y > height - 1) y = 0;
    for(int j = 0;j<ntail;j++)
    	if(x == tailX[j] && y == tailY[j])
    		gameOver = true;
    if(x == fruitX && y == fruitY)
    {
    	score+=10;
    	srand(time(0));
    	fruitX = rand() % (width - 2);
   		fruitY = rand() % (height - 2);
   		ntail++;
        if(speed_snake > 15 && score%50 == 0)
            speed_snake -= 10;
	}
	prevdir = dir;
}


int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
        _sleep(speed_snake);
    }
    cout << "\nGOOD GAME";
    return 0;
}
