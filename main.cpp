// #include <windows.h>
// #include <conio.h>
// #include <iostream>
// #include <deque>

// using namespace std;

// #define HEIGHT 20
// #define WIDTH 50
// enum eDIRECTION {STOP = 0, UP, DOWN, LEFT, RIGHT};

// int snakeHeadX=WIDTH/2, snakeHeadY=HEIGHT/2;

// deque<pair<int,int>> Snake;

// int snakeSize = 2;
// int foodX=rand()% (WIDTH - 2) + 1, foodY=rand()% (HEIGHT - 2) + 1;
// int w=80, h=20;
// eDIRECTION dir = STOP;
// bool gameover = false;
// bool isEat = false;

// void clearCursor(){
//     COORD coord;
//     coord.X = 0;
//     coord.Y = 0;
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//     Sleep(5);
// }

// void initScreen(){
//     clearCursor();
//     for (int i=0; i<HEIGHT; ++i){
//         for (int j=0; j<WIDTH; ++j){
//             if(0==i || HEIGHT-1==i)
//                 cout << '#';
//             else if(0==j || WIDTH-1==j)
//                 cout << '#';
//             else
//                 cout << " ";
//         }
//         cout << endl;
//     }

//     COORD coord;
//     int snakeHeadX = Snake.front().first;
//     int snakeHeadY = Snake.front().second;
//     coord.X = snakeHeadX;
//     coord.Y = snakeHeadY;
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//     cout << "O";

//     int snakeTailX = Snake.back().first;
//     int snakeTailY = Snake.back().second;
//     coord.X = snakeTailX;
//     coord.Y = snakeTailY;
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//     cout << "O";

//     coord.X = foodX;
//     coord.Y = foodY;
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//     cout << "*";
// }
// void Controller(){
//     if (kbhit()){
//         int c = getch();
//         // cout << c << endl;
//         switch(c){
//             case 'a': if(dir!=RIGHT) dir = LEFT; break;
//             case 's': if(dir!=UP) dir = DOWN; break;
//             case 'd': if(dir!=LEFT) dir = RIGHT; break;
//             case 'w': if(dir!=UP) dir = UP; break;
//             default: break;
//         }
//     }
// }
// void Model(){
//     isEat = false;
//     int snakeHeadX = Snake.front().first;
//     int snakeHeadY = Snake.front().second;
//     cout << " ";
//     switch(dir){
//         case LEFT: snakeHeadX--; if(snakeHeadX<=0) snakeHeadX = WIDTH-2; break;
//         case DOWN: snakeHeadY++; if(snakeHeadY>=HEIGHT-1) snakeHeadY = 1; break;
//         case RIGHT: snakeHeadX++; if(snakeHeadX>=WIDTH-1) snakeHeadX = 1; break;
//         case UP: snakeHeadY--; if(snakeHeadY<=0) snakeHeadY = HEIGHT-2; break;
//         default: break;
//     }
//     Snake.push_front(make_pair(snakeHeadX,snakeHeadY));
//     if(foodX==snakeHeadX && foodY==snakeHeadY)
//     {
//         foodX=rand()% (WIDTH - 2) + 1; foodY=rand()% (HEIGHT - 2) + 1;
//         snakeSize++;
//         isEat = true;
//     }
    
//     // cout << foodX << "  " << foodY << endl;
// }

// void Render(){
//     COORD coord;
//     if(!isEat){
//         int snakeTailX = Snake.back().first;
//         int snakeTailY = Snake.back().second;
//         Snake.pop_back();
//         coord.X = snakeTailX;
//         coord.Y = snakeTailY;
//         SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//         cout << " ";
//     }
//     int snakeHeadX = Snake.front().first;
//     int snakeHeadY = Snake.front().second;
//     coord.X = snakeHeadX;
//     coord.Y = snakeHeadY;
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//     cout << "O";

//     coord.X = foodX;
//     coord.Y = foodY;
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//     cout << "*";
//     clearCursor();
// }

// int main(int argc, char* argv[]){
//     Snake.push_front(make_pair(snakeHeadX,snakeHeadY));
//     Snake.push_back(make_pair(snakeHeadX-1,snakeHeadY));
//     initScreen();
//     for(;;){
//         Controller();
//         Model();
//         Render();
//         Sleep(100);
//     }
//     return 0;
// }