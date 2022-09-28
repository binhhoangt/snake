#ifndef SNAKE_H_
#define SNAKE_H_

#include <deque>
#include<iostream>
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

    Snake(){}

    void init(Point snakeHead, Point snakeTail){   
        this->snake.push_front(snakeHead);
        this->snake.push_back(snakeTail);
    }
private:
    std::deque<Point> snake;
};

#endif // SNAKE_H_