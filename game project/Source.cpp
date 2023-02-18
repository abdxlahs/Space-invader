#include <iostream>
#include "mygraphics.h"
#include "myconsole.h"
#include<windows.h>
#include<fstream>


using namespace std;
void gotoxy(int x, int y)
{
    COORD c;         /* Using column number as x-coordinate and row number as y-coordinate*/
    c.X = y;
    c.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void scr(int score) {
    int a, b, c, d, e;
    ifstream ione("a.txt");
    ione >> a;
    ifstream itwo("b.txt");
    itwo >> b;
    ifstream ithree("c.txt");
    ithree >> c;
    ifstream ifour("d.txt");
    ifour >> d;
    ifstream ifive("e.txt");
    ifive >> e;
    if (score > a) {
        a = score;
        ofstream one("a.txt");
        one << a;
    }
    else if (score > b && score < a) {
        b = score;
        ofstream two("b.txt");
        two << b;
    }
    else if (score > c && score < b) {
        c = score;
        ofstream three("c.txt");
        three << c;
    }
    else if (score > d && score < c) {
        d = score;
        ofstream four("d.txt");
        four << d;
    }
    else if (score > e && score < d) {
        e = score;
        ofstream five("e.txt");
        five << e;
    }

    gotoxy(0, 10);
    cout << endl;
    cout << " High Scores" << endl;
    cout << "   " << a << endl;
    cout << "   " << b << endl;
    cout << "   " << c << endl;
    cout << "   " << d << endl;
    cout << "   " << e << endl;
}

int main()

{
    char start[] = "PRESS n TO START NEW GAME OR l TO START LOADED GAME";
    myDrawText(10, 0, 50, start, RGB(255, 200, 255), RGB(20, 20, 20));
    char c;
    cin >> c;
    ClearScreen();
        ifstream input;
        ofstream output;
        int total_score = 0;
        bool hit = false;
        int win_x, win_y;
        int box_x = 0;
        int box_y = 0;
        int out = 0;
        int ball_x, ball_y;
        bool flag = true;
        char PAUSED[] = "GAME PAUSED";
        char menue[] = "PRESS y TO QUIT OR r TO RESUME";
        char space[] = "space invade game by ABDX";
        char save[] = "PRESS s TO SAVE THE GAME";
        int lifes = 3;
        int score = 0;
        GetWindowDimensions(win_x, win_y);
        SetWindowTitle(space);
        box_x = 10;
        ball_x = win_x / 2;
        ball_y = win_y - 50;
        int f = 0;

        struct tags
        {
            int x1 = 0;
            int y1 = 0;
            int x2 = 0;
            int y2 = 0;
            int col = 255;
            bool hit = false;
            bool alive = false;

        };
        tags aliensadd[5][10];
        tags Fire;
        float down = 0;

        bool pause = true;
        if (c == 'l')
        {
            input.open("ballx.txt");
            input >> ball_x;
            input.close();
            input.open("bally.txt");
            input >> ball_y;
            input.close();
            input.open("boxy.txt");
            input >> down;
            input.close();
            input.open("lifes.txt");
            input >> lifes;
            input.close();

        }
    
            while (flag == true && lifes>0 && score!=50 && box_y<466)
            {
                //for printing lives
                int lifeball = 650;
                for (int x = 0; x < lifes; x++)
                {

                    myEllipse(lifeball, 0, lifeball + 50, 0 + 50, RGB(255, 0, 0), RGB(255, 0, 0));
                    lifeball = lifeball + 50;
                }
                bool alive = false;
                myLine(ball_x + 25, ball_y, ball_x + 25, ball_y - 5, RGB(255, 255, 0));
                //for aliens
                box_x = 0, box_y = down;
                for (int y = 0; y < 5; y++)
                {
                    for (int x = 0; x < 10; x++)
                    {
                        myRect(box_x, box_y, box_x + 50, box_y + 50, RGB(0, aliensadd[y][x].col, 0), RGB(0, aliensadd[y][x].col, 0));
                        box_x = box_x + 60;
                        
                    }
                    box_x = 0;
                    box_y = box_y + 60;
                }
               
                
                //for setting tags on alliens

                box_x = 0, box_y = down;

                for (int y = 0; y < 5; y++)
                {
                    for (int x = 0; x < 10; x++)
                    {
                        aliensadd[y][x].x1 = box_x;
                        aliensadd[y][x].x2 = box_x + 50;
                        aliensadd[y][x].y1 = box_y;
                        aliensadd[y][x].y2 = box_y + 50;
                        box_x = box_x + 60;
                    }
                    box_x = 0;
                    box_y = box_y + 60;
                }
               myEllipse(ball_x, ball_y, ball_x + 50, ball_y + 50, RGB(0, 0, 255), RGB(0, 255, 255));

                //  move ball with left and right arrow keys. press space to change text
                int a = CheckKeyPressed();
               
                
                 if (a == LEFTKEY) {
                     
                    ball_x -= 50;
                }
                else if (a == RIGHTKEY) {
                     input.open("ballx.txt");
                    ball_x += 50;
                    input.close();
                }
                else if (a == UPKEY) {
                     input.open("bally.txt");
                    ball_y -= 50;
                    input.close();
                   
                }
                else if (a == DOWNKEY)
                {
                     input.open("bally.txt");
                    ball_y += 50;
                    input.close();
                   
                }
          
                else if (a == 27 && pause==true )
                {
                     
                     ClearScreen();
                     myDrawText(win_x / 2, 50, 50, PAUSED, RGB(255, 200, 255), RGB(20, 20, 20));
                     myDrawText(win_x / 2, 100, 50, menue, RGB(255, 200, 255), RGB(20, 20, 20));
                     myDrawText(win_x / 2, 150, 50, save, RGB(255, 200, 255), RGB(20, 20, 20));
                     gotoxy(0, 0);
                     cout <<"your score is"<< score;
                     
                     scr(score);

                     cin >> c;
                     if (c == 'y')
                     {
                         flag = false;
                     }
                     if (c == 'r')
                     {
                         pause = false;
                     }
                     if (c == 's')
                     {
                         output.open("ballx.txt");
                         output << ball_x;
                         output.close();
                         output.open("bally.txt");
                         output << ball_y;
                         output.close();
                         output.open("boxy.txt");
                         output << down;
                         output.close();
                         output.open("lifes.txt");
                         output << lifes;
                         output.close();
                         
                     }


                }
                
                else if (a == 32)
                {
                    int y = ball_y - 30;
                    while (y > 0)
                    {

                        myLine(ball_x + 25, y, ball_x + 25, y - 10, RGB(255, 255, 0));
                        Fire.y1 = y;
                        Fire.y2 = y - 10;
                        Fire.x1 = ball_x + 25;
                        Fire.x2 = ball_x + 25;
                        for (int i = 0; i < 5; i++)
                        {
                            for (int j = 0; j < 10; j++)
                            {
                                if (Fire.y1 < aliensadd[i][j].y2 && Fire.y2 > aliensadd[i][j].y1 && Fire.x1 > aliensadd[i][j].x1 && Fire.x2 < aliensadd[i][j].x2 && aliensadd[i][j].alive == false)
                                {
                                    aliensadd[i][j].col = 0;
                                    alive = true;
                                    aliensadd[i][j].alive = true;
                                    score++;
                                   
                                    Beep(20, 800);

                                }
                            }
                        }
                        if (alive)
                        {
                            break;
                        }
                        y = y - 15;
                        ClearScreen();
                        myEllipse(ball_x, ball_y, ball_x + 50, ball_y + 50, RGB(0, 0, 255), RGB(0, 255, 255));
                       
                        //for alines
                        box_x = 0, box_y = down;
                        
                        for (int y = 0; y < 5; y++)
                        {
                            for (int x = 0; x < 10; x++)
                            {

                                myRect(box_x, box_y, box_x + 50, box_y + 50, RGB(0, aliensadd[y][x].col, 0), RGB(0, aliensadd[y][x].col, 0));
                                box_x = box_x + 60;
                            }
                            box_x = 0;
                            box_y = box_y + 60;
                        }
                    }
                }
                 pause = true;
                bool counter = false;
                //check for clash

                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        if ((ball_y <= aliensadd[i][j].y2 || ball_y + 50 <= aliensadd[i][j].y2) && (ball_y >= aliensadd[i][j].y1 || ball_y + 50 >= aliensadd[i][j].y1) && (ball_x >= aliensadd[i][j].x1 || ball_x + 50 >= aliensadd[i][j].x1) && (ball_x <= aliensadd[i][j].x2 || ball_x + 50 <= aliensadd[i][j].x2) && aliensadd[i][j].alive == false && aliensadd[i][j].hit == false)
                        {
                            lifes--;
                            aliensadd[i][j].hit = true;
                            aliensadd[i][j].alive = true;
                            aliensadd[i][j].col = 0;
                            counter = true;
                            break;
                        }
                    }
                    if (counter)
                        break;
                }
                down = down + 0.5;
                ClearScreen();
            }
            cout << "game over";
}


    
    



