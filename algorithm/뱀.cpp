#include <iostream>
#include <queue>
using namespace std;

int applesRow[100] = {-1};
int applesCol[100] = {-1};
int appleNum = 0;

enum Direction
{
    RIGHT, 
    LEFT, 
    UP, 
    DOWN
};

bool checkApple(int x, int y ) {
    bool appleEat = false;
    for(int i  = 0 ; i < appleNum ; ++i) {
        if(applesRow[i] == x && applesCol[i] == y) {
            appleEat = true;
            applesRow[i] = -1;
            applesCol[i] = -1;
            break;
        }
    }
    return appleEat;
}

int main() {
    int boardSize, directionNum;
    int commandSeconds[100];
    char commandDirections[100];
    int boards[101][101]= {0};
    int direction = RIGHT;
    int commandIndex;
    int time;
    int tailX, tailY, headX, headY;
    queue<pair<int, int> > snake;
    commandIndex = time = 0;
    headX = headY = 1;
    boards[tailX][tailY] = 1;
    snake.push(make_pair(tailX, tailY));
    //intialize
    cin >> boardSize >> appleNum;
    for(int i = 0 ; i < appleNum ; ++ i) {
        cin >> applesRow[i];
        cin >> applesCol[i];
    }
    cin >> directionNum;
    for(int i = 0 ; i < directionNum ; ++ i) {
        cin >> commandSeconds[i];
        cin >> commandDirections[i];
    }
    //solution
    while(true) {
        time++;
        //Right D -> Down L ->Up
        //Left D -> Up L -> Down
        //Up D -> Right L -> LEFT
        //Down D -> Left L -> right
        if(direction == RIGHT) {
            //move to right
            headY++;
            if((headX > boardSize || headX <=0) || (headY > boardSize || headY <=0)) {
                break;
            }
            if(boards[headX][headY] == 1) {
                break;
            }
            boards[headX][headY] = 1;
            snake.push(make_pair(headX,headY));
            //check apple is there
            //if there is no apple then remove before location's tail
            //and update tail location X and Y to 
            if(!checkApple(headX, headY)) {
                tailX = snake.back().first;
                tailY = snake.back().second;
                boards[tailX][tailY] = 0;
                snake.pop();
            }
            //check command is equal time. if time is equal commandSecond. update direction
            if(commandSeconds[commandIndex] == time) {
                if(commandDirections[commandIndex] == 'D') {
                    direction = DOWN;
                }
                else if(commandDirections[commandIndex] == 'L') {
                    direction = UP;
                }
                ++commandIndex;
            }
        } // end of right   
        if(direction == LEFT) {
            //move to right
            headY--;
            if((headX > boardSize || headX <=0) || (headY > boardSize || headY <=0)) {
                break;
            }
            if(boards[headX][headY] == 1) {
                break;
            }
            boards[headX][headY] = 1;
            snake.push(make_pair(headX,headY));
            //check apple is there
            //if there is no apple then remove before location's tail
            //and update tail location X and Y to 
            if(!checkApple(headX, headY)) {
                tailX = snake.back().first;
                tailY = snake.back().second;
                boards[tailX][tailY] = 0;
                snake.pop();
            }
            //check command is equal time. if time is equal commandSecond. update direction
            if(commandSeconds[commandIndex] == time) {
                if(commandDirections[commandIndex] == 'D') {
                    direction = UP;
                }
                else if(commandDirections[commandIndex] == 'L') {
                    direction = DOWN;
                }
                ++commandIndex;
            }
        } // end of LEFT
       if(direction == UP) {
            //move to right
            headX--;
            if((headX > boardSize || headX <=0) || (headY > boardSize || headY <=0)) {
                break;
            }
            if(boards[headX][headY] == 1) {
                break;
            }
            boards[headX][headY] = 1;
            snake.push(make_pair(headX,headY));
            //check apple is there
            //if there is no apple then remove before location's tail
            //and update tail location X and Y to 
            if(!checkApple(headX, headY)) {
                tailX = snake.back().first;
                tailY = snake.back().second;
                boards[tailX][tailY] = 0;
                snake.pop();
            }
            //check command is equal time. if time is equal commandSecond. update direction
            if(commandSeconds[commandIndex] == time) {
                if(commandDirections[commandIndex] == 'D') {
                    direction = RIGHT;
                }
                else if(commandDirections[commandIndex] == 'L') {
                    direction = LEFT;
                }
                ++commandIndex;
            }
        } // end of UP
       if(direction == DOWN) {
            //move to right
            headX++;
            if((headX > boardSize || headX <=0) || (headY > boardSize || headY <=0)) {
                break;
            }
            if(boards[headX][headY] == 1) {
                break;
            }
            boards[headX][headY] = 1;
            snake.push(make_pair(headX,headY));
            //check apple is there
            //if there is no apple then remove before location's tail
            //and update tail location X and Y to 
            if(!checkApple(headX, headY)) {
                tailX = snake.back().first;
                tailY = snake.back().second;
                boards[tailX][tailY] = 0;
                snake.pop();
            }
            //check command is equal time. if time is equal commandSecond. update direction
            if(commandSeconds[commandIndex] == time) {
                if(commandDirections[commandIndex] == 'D') {
                    direction = LEFT;
                }
                else if(commandDirections[commandIndex] == 'L') {
                    direction = RIGHT;
                }
                ++commandIndex;
            }
        } // end of LEFT
    }
    cout<< time <<endl;
    return 1;
}