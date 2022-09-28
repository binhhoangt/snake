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
bool gameover = false;
int box[WIDTH][HEIGHT];

eDIRECTION getKeyHandler(){
    eDIRECTION dir = NONE;
    if (kbhit()){
        int c = getch();
        // cout << c << endl;
        switch(c){
            case 'a': dir = LEFT; break;
            case 's': dir = DOWN; break;
            case 'd': dir = RIGHT; break;
            case 'w': dir = UP; break;
            default: break;
        }
    }
    return dir;
}

void update(eDIRECTION dir){
    bool isEat = false;
    Point snakeHead = snake.getHead();
    Point snakeTail = snake.getTail();
    Point f = food.getFood();

    switch(dir){
        case LEFT: snakeHead.x--; if(snakeHead.x<=0) snakeHead.x = WIDTH-2; break;
        case DOWN: snakeHead.y++; if(snakeHead.y>=HEIGHT-1) snakeHead.y = 1; break;
        case RIGHT: snakeHead.x++; if(snakeHead.x>=WIDTH-1) snakeHead.x = 1; break;
        case UP: snakeHead.y--; if(snakeHead.y<=0) snakeHead.y = HEIGHT-2; break;
        case NONE: return;
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
    eDIRECTION dir=NONE, previous_dir=NONE;
    Point head = {.x=WIDTH/2, .y=HEIGHT/2};
    Point tail = {.x=WIDTH/2-1, .y=HEIGHT/2};

    snake.init(head, tail);
    memset(box,0,sizeof(box));
    box[head.x][head.y] = 1;
    box[tail.x][tail.y] = 1;
    render.initScreen(snake, food);

    do{
        dir = getKeyHandler();
        if(dir==RIGHT&&previous_dir==LEFT || dir==LEFT&&previous_dir==RIGHT \
            || dir==DOWN&&previous_dir==UP || dir==UP&&previous_dir==DOWN \ 
            || dir==NONE && previous_dir!=NONE )
            dir = previous_dir;
        else if(dir==NONE && previous_dir==NONE)
            continue;
        else
            previous_dir = dir;
        update(dir);
        Sleep(100);
    } while(!gameover);
    render.cleanScreen();
    render.gameOver();
    getch();
    
    return 0;
}