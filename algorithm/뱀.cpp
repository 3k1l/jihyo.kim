#include <iostream>
#include <queue>
using namespace std;
//apples
int applesRow[100] = {-1};
int applesCol[100] = {-1};
int appleNum = 0;
//boards
int boards[101][101]= {0};
int boardSize;
//snake
queue<pair<int, int> > snake;
//commands
int commandNum;
int commandSeconds[100];
char commandDirections[100];
//direction
enum Direction
{
    RIGHT, 
    LEFT, 
    UP, 
    DOWN
};

void checkApple(int x, int y ) {
    bool appleEat = false;
    int tailX, tailY;
    for(int i  = 0 ; i < appleNum ; ++i) {
        if(applesRow[i] == x && applesCol[i] == y) {
            appleEat = true;
            applesRow[i] = -1;
            applesCol[i] = -1;
            break;
        }
    }
    if(!appleEat) {
        tailX = snake.front().first;
        tailY = snake.front().second;
        boards[tailX][tailY] = 0;
        snake.pop();
    }
}

bool checkDie(int headX, int headY) {
    if(headX > boardSize || headX <=0 || headY > boardSize || headY <=0) {
        return true;
    }
    if(boards[headX][headY] == 1) {
        return true;
    }
    return false;
}

bool checkCommand(int time, int commandIndex) {
    if(commandNum <= commandIndex)
        return false;
    if(commandSeconds[commandIndex] == time) 
        return true;
    return false;
}

int main() {
    int direction = RIGHT;
    int commandIndex;
    int time;
    int headX, headY;
    
    commandIndex = time = 0;
    headX = headY = 1;
    boards[headX][headX] = 1;
    snake.push(make_pair(headX, headX));
    //intialize
    cin >> boardSize >> appleNum;
    for(int i = 0 ; i < appleNum ; ++ i) {
        cin >> applesRow[i];
        cin >> applesCol[i];
    }
    cin >> commandNum;
    for(int i = 0 ; i < commandNum ; ++ i) {
        cin >> commandSeconds[i];
        cin >> commandDirections[i];
    }
    //solution
    while(true) {
        time++;
        if(direction == RIGHT) {
            //move to right
            headY++;
            if(checkDie(headX, headY)) {
                break;
            }
            boards[headX][headY] = 1;
            snake.push(make_pair(headX,headY));
            //if there is no apple then remove before location's tail
            //and update tail location X and Y to 
            checkApple(headX, headY);
            //check command is equal time. if time is equal commandSecond. update direction
            if(checkCommand(time, commandIndex)) {
                if(commandDirections[commandIndex] == 'D') {
                    direction = DOWN;
                }
                else if(commandDirections[commandIndex] == 'L') {
                    direction = UP;
                }
                ++commandIndex;
            }
        } // end of right   
        else if(direction == LEFT) {
            //move to right
            headY--;
            if(checkDie(headX, headY)) {
                break;
            }
            boards[headX][headY] = 1;
            snake.push(make_pair(headX,headY));
            //if there is no apple then remove before location's tail
            //and update tail location X and Y to 
            checkApple(headX, headY);
            //check command is equal time. if time is equal commandSecond. update direction
            if(checkCommand(time, commandIndex)) {
                if(commandDirections[commandIndex] == 'D') {
                    direction = UP;
                }
                else if(commandDirections[commandIndex] == 'L') {
                    direction = DOWN;
                }
                ++commandIndex;
            }
        } // end of LEFT
       else if(direction == UP) {
            //move to right
            headX--;
            if(checkDie(headX, headY)) {
                break;
            }
            boards[headX][headY] = 1;
            snake.push(make_pair(headX,headY));
            //if there is no apple then remove before location's tail
            //and update tail location X and Y to 
            checkApple(headX, headY);
            //check command is equal time. if time is equal commandSecond. update direction
            if(checkCommand(time, commandIndex)) {
                if(commandDirections[commandIndex] == 'D') {
                    direction = RIGHT;
                }
                else if(commandDirections[commandIndex] == 'L') {
                    direction = LEFT;
                }
                ++commandIndex;
            }
        } // end of UP
       else if(direction == DOWN) {
            //move to right
            headX++;
            if(checkDie(headX, headY)) {
                break;
            }
            boards[headX][headY] = 1;
            snake.push(make_pair(headX,headY));
            //if there is no apple then remove before location's tail
            checkApple(headX, headY);
            //check command is equal time. if time is equal commandSecond. update direction
            if(checkCommand(time, commandIndex)) {
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
    return 0;
}