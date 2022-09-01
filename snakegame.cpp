#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int dai=100;
const int rong=50;
enum Direction{stop=0, LEFT, RIGHT, up, down};
Direction direction;
int x, y, fruitx, fruity, score;
int tailX[100];
int tailY[100];
int nTail;
void Setup()
{
    gameOver=false;
    direction=stop;
    x=dai/2;
    y=rong/2;
    fruitx=rand()%dai;
    fruity=rand()%rong;
}
void Draw()
{
//    system("cls");
    for (int i=0; i<rong; i++)
    {
        for (int j=0;j<dai; j++)
        {
            if ((i==0)||(i==rong-1))
            {
                printf("#");
            }
            else if ((j==0)||(j==dai-1))
            {
                printf("#");
            }
            else if ((i==x)&&(j==y))
            {
                printf("0");
            }
            else if ((i==fruitx)&&(j==fruity))
            {
                printf("$");
            }
            else
            {
                bool print=false;
                for (int k=0; k<nTail; k++)
                {
                    if ((tailX[k]==i)&&(tailY[k]==j))
                    {
                        printf("o");
                        print=true;
                    }
                }
                if (!print)
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("Score: %d\n",score);
}
void Input()
{
    if (_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            direction=LEFT;
            break;

        case 'd':
            direction=RIGHT;
            break;

        case 'w':
            direction=up;
            break;

        case 's':
            direction=down;
            break;

        case 'x':
            gameOver=true;
            break;
        }
    }
}
void Logic()
{
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prevX2, prevY2;
    tailX[0]=x;
    tailY[0]=y;
    for (int i=1; i<nTail; i++)
    {
        prevX2=tailX[i];
        prevY2=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prevX2;
        prevY=prevY2;
    }
    switch(direction)
    {
    case LEFT:
        y--;
        break;
    case RIGHT:
        y++;
        break;
    case up:
        x--;
        break;
    case down:
        x++;
        break;
        default:
            break;
    }
    if ((x>dai)||(x<0)||(y>rong)||(y<0))
        {
            gameOver=true;
        }
    for (int i=0; i<nTail; i++)
    {
        if ((tailX[i]==x)&&(tailY[i]==y))
        {
            gameOver=true;
        }
    }
    if((x==fruitx)&&(y==fruity))
    {
        score+=10;
        fruitx=rand()%dai;
        fruity=rand()%rong;
        nTail++;
    }
}
int main()
{
    Setup();
    while (gameOver!=true)
    {
        Draw();
        Input();
        Logic();
        Sleep(30);
    }
}
