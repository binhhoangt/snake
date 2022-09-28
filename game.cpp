#include <conio.h>
#include <windows.h>
#include <iostream>

#include "Snake.hpp"
#include "Food.hpp"
#include "Render.hpp"
#include "global.hpp"

using namespace std;

Snake snake;
Food food;
Render render;

eDIRECTION dir = RIGHT;
bool gameover = false;
bool isEat = false;
int box[WIDTH][HEIGHT];

void Controller(){
    if (kbhit()){
        int c = getch();
        // cout << c << endl;
        switch(c){
            case 'a': if(dir!=RIGHT) dir = LEFT; break;
            case 's': if(dir!=UP) dir = DOWN; break;
            case 'd': if(dir!=LEFT) dir = RIGHT; break;
            case 'w': if(dir!=UP) dir = UP; break;
            default: break;
        }
    }
}
void Model(){
    isEat = false;
    Point snakeHead = snake.getHead();
    Point snakeTail = snake.getTail();
    Point f = food.getFood();

    switch(dir){
        case LEFT: snakeHead.x--; if(snakeHead.x<=0) snakeHead.x = WIDTH-2; break;
        case DOWN: snakeHead.y++; if(snakeHead.y>=HEIGHT-1) snakeHead.y = 1; break;
        case RIGHT: snakeHead.x++; if(snakeHead.x>=WIDTH-1) snakeHead.x = 1; break;
        case UP: snakeHead.y--; if(snakeHead.y<=0) snakeHead.y = HEIGHT-2; break;
        case STOP: return;
        default: break;
    }
    // cout <<  snakeHead.x << " " << snakeHead.y << endl;
    // cout <<  snakeTail.x << " " << snakeTail.y << endl;
    if(box[snakeHead.x][snakeHead.y]==1){
        gameover = true;
        return;
    }
    
    if(f.x==snakeHead.x && f.y==snakeHead.y)
    {
        food.generateFood();
        render.updateFood(food);
        isEat = true;
    }
    
    if(!isEat)
        box[snakeTail.x][snakeTail.y] = 0;

    box[snakeHead.x][snakeHead.y] = 1;
    snake.udpateHead(snakeHead);

    render.updateSnake(snake, isEat);

    snake.udpateTail(isEat);
}

int main(int argc, char* argv[]){
    render.initScreen(snake, food);
    memset(box,0,sizeof(box));
    box[WIDTH/2][HEIGHT/2] = 1;
    box[WIDTH/2-1][HEIGHT/2] = 1;
    do{
        Controller();
        Model();
        Sleep(100);
    } while(!gameover);
    render.cleanScreen();
    render.gameOver();
    getch();
    
    return 0;
}