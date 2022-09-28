#ifndef FOOD_H_
#define FOOD_H_

#include "global.hpp"

class Food{
public:
    void updateFood(Point p){
        this->food = p;
    }
    Point getFood() const {
        return food;
    }

    void generateFood() {
        Point newFood;
        newFood.x=rand()% (WIDTH - 2) + 1;
        newFood.y=rand()% (HEIGHT - 2) + 1;
        this->food = newFood;
    }

    Food(){
        this->generateFood();
    }
private:
    Point food;
};

#endif // FOOD_H_
