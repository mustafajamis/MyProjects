#include <iostream>
#include "Snake.h"
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
// Using enum because by default it will assign number to our parameters 
enum eDirection {STOP = 0, LEFT, RIGHT, UP , DOWN};
eDirection dir;

int main() {

    setUp();
    while (!gameOver) {

        Draw();
        Input();
        Logic();
        // use this according your cpu speed
        Sleep(30); //lux sleep()
    }

}

// Use the setUp to begin our program with
void setUp() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    // using the rnad() to get random fruit in mape
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
// Usign the draw function to draw a map.
void Draw() {
    // Cleanup our terminal "clear"
    system("cls");
    for(int i = 0; i< width+2; i++) {
        cout<<"*";
    }
    cout<<endl;
    for (int i = 0; i < height;i++) {
        for(int j = 0; j < width;j++) {
            if(j == 0){
            cout<<"*";
            }
            if(i == y && j == x) {
                cout<<"O";
            } else if (i == fruitY && j == fruitX){
                cout<<"F";
            }
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++){
                    if(tailX[k] == j && tailY[k] == i ){
                        cout<<"o";
                        print = true;
                    }
                }
                if(!print) {
                    cout<<" ";
                }
            } 
            if(j == width - 1){
            cout<<"*";
            }
            }

        cout<<endl;
    }
        for(int i = 0; i< width+2; i++) {
            cout<<"*";
        }
        cout<<endl;
        cout<<"Score: "<<score<<endl;
    
}

void Input() {
//_kbhit is macro which come from the conio header if charater in keyboard is press return 1 if not return 0
    if(_kbhit()) {

        switch(_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
        
    }

}
void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;
    for(int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;

    }
 switch (dir)
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
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
    //if(x > width || x < 0 || y > height || y < 0){
     //   gameOver = true;
   // }
    for (int i =0; i < nTail; i++){
        if(tailX[i]==x && tailY[i] == y){
            gameOver = true;
        }
    }
    if (x == fruitX && y == fruitY) {
   
        score = score+10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}
