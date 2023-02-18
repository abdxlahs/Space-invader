#include <iostream>
#include "mygraphics.h"
#include "myconsole.h"
using namespace std;

int main()
{
    int win_x, win_y;
    int box_x, box_y;
    int ball_x, ball_y;
    bool dir = false;
    bool flag = true;
    char demo[] = "demo";
    char space[] = "space";
    bool pressed = false;

    //system("pause");

    GetWindowDimensions(win_x, win_y);
    SetWindowTitle(demo);

    box_x = 0;
    box_y = 0;
    ball_x = win_x / 2;
    ball_y = win_y - 50;
  
    
    PlaceCursor(0, 0);
    while (flag) {			//GAME LOOP
        
		//BOX MOVEMENT
		box_x += 25 - dir * 50;
        if (box_x + 50 >= win_x || box_x <= 0)
            dir = !dir;

        //MOVE BALL WITH LEFT AND RIGHT ARROW KEYS. PRESS SPACE TO CHANGE TEXT
        int a = CheckKeyPressed();
        if (a == LEFTKEY)
            ball_x -= 50;
        else if (a == RIGHTKEY)
            ball_x += 50;
        else if (a == 27)
            flag = false;
        else if (a == 32)
            pressed = !pressed;
        
        //Sleep(10);

		//CLEAR PREVIOUS FRAME
        ClearScreen();
		
		//RENDER NEW FRAME
        myLine(0, win_y / 2 - 10, win_x, win_y / 2 - 10, RGB(255,255,0));
        myRect(box_x, box_y, box_x + 50, box_y + 50, RGB(255, 0, 0), RGB(255, 0, 0));
        if (pressed)
            myDrawTextWithFont(win_x / 2, win_y / 2, 20, space, RGB(0, 255, 0), RGB(20, 20, 20));
        else
            myDrawTextWithFont(win_x / 2, win_y / 2, 20, demo, RGB(0, 255, 0), RGB(20, 20, 20));

        mySetPixel(win_x / 2, win_y / 2 + 100, RGB(0, 255, 0));
        myEllipse(ball_x, ball_y, ball_x + 50, ball_y + 50, RGB(0, 0, 255), RGB(0, 255, 255));
    }
    
}
