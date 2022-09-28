#ifndef SNAKE_H_
#define SNAKE_H_

#include <deque>
#include<iostream>
#include "Point.hpp"
#include "Food.hpp"

class Snake{
public:
    Point getHead(){
        return this->snake.front();
    }
    Point getTail(){
        return this->snake.back();
    }
    void feedSnake(Food f){
        this->snake.push_front(f.getFood());
    }
    void udpateTail(bool isEat){
        if(!isEat)
            this->snake.pop_back();
    }

    void udpateHead(Point p){
        this->snake.push_front(p);
    }
    Snake(){
        Point snakeHead, snakeTail;
        snakeHead.x = WIDTH/2;
        snakeHead.y = HEIGHT/2;
        snakeTail.x = snakeHead.x-1;
        snakeTail.y = snakeHead.y;       
        this->snake.push_front(snakeHead);
        this->snake.push_back(snakeTail);
    }
private:
    std::deque<Point> snake;
};

#endif // SNAKE_H_