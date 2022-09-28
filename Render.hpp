#ifndef RENDER_H_
#define RENDER_H_

#include <windows.h>
#include<iostream>
#include"global.hpp"

class Render{
public:
    void gameOver(){
        coord.X = WIDTH/2-5;
        coord.Y = HEIGHT/2;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "Game over!!!";
    }
    void cleanScreen(){
        clearCursor();

        for (int i=0; i<HEIGHT; ++i){
            for (int j=0; j<WIDTH; ++j){
                if(0==i || HEIGHT-1==i)
                    std::cout << '#';
                else if(0==j || WIDTH-1==j)
                    std::cout << '#';
                else
                    std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
    void initScreen(Snake snake, Food food){
        cleanScreen();

        Point f = food.getFood();
        coord.X = f.x;
        coord.Y = f.y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "*";

        Point snakeHead = snake.getHead();
        coord.X = snakeHead.x;
        coord.Y = snakeHead.y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "O";

        Point snakeTail = snake.getTail();
        coord.X = snakeTail.x;
        coord.Y = snakeTail.y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "O";
        clearCursor();
    }

    void updateSnake(Snake snake, bool isEat){
        // clearCursor();
        Point snakeHead = snake.getHead();
        coord.X = snakeHead.x;
        coord.Y = snakeHead.y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "O";

        if(!isEat){
            Point snakeTail = snake.getTail();
            // snake.udpateTail();
            coord.X = snakeTail.x;
            coord.Y = snakeTail.y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            std::cout << " ";
            // clearCursor();
        }
        clearCursor();
    }
    void updateFood(Food food){
        Point f = food.getFood();
        coord.X = f.x;
        coord.Y = f.y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << "*";
        clearCursor();
    }
private:
    COORD coord;
    void clearCursor(){
        coord.X = 0;
        coord.Y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        // Sleep(20);
    }
};

#endif // RENDER_H_