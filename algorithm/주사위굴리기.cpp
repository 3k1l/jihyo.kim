#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

enum direction {
    EAST = 1,
    WEST, 
    NORTH, 
    SOUTH
};
enum side{
    TOP, FRONT ,BOTTOM, BACK, LEFT, RIGHT
};
int main() {
    int row, col, x, y, num, directionNum;
    scanf("%d %d %d %d %d", &row, &col, &x, &y, &num);
    int boards[21][21];
    vector<int> dice(6, 0);
    for(int i = 0; i < row ; ++i) {
        for(int j = 0 ; j < col ; ++j) {
            scanf("%d", &boards[i][j]);
        }
    }

    for(int i = 0 ; i < num ; ++i) {
        cin>>directionNum;        
        if(directionNum == EAST) {
            if(boards[x][y] == 0) {
                //copy dice to board
                boards[x][y] = dice[BOTTOM];
            }
            else {
                //copy board to dice
                dice[BOTTOM] = boards[x][y];
                boards[x][y] = 0;
            }
            //update coordinate
            //East ++y
            ++y;
            if(y >= col) {
                --y;
                continue;
            }
            else {
                //roll the dice
                swap(dice[TOP], dice[LEFT]);
                swap(dice[BOTTOM], dice[RIGHT]);
                swap(dice[LEFT], dice[RIGHT]);
                printf("%d\n",dice[TOP]);
            }
        }
        else if(directionNum == WEST) {
            if(boards[x][y] == 0) {
                //copy dice to board
                boards[x][y] = dice[BOTTOM];
            }
            else {
                //copy board to dice
                dice[BOTTOM] = boards[x][y];
                boards[x][y] = 0;
            }
            //update coordinate
            --y;
            if(y < 0) {
                ++y;
                continue;
            }
            else {
                //roll the dice
                swap(dice[TOP], dice[RIGHT]);
                swap(dice[BOTTOM], dice[LEFT]);
                swap(dice[LEFT], dice[RIGHT]);
                printf("%d\n",dice[TOP]);
            }
        }
        else if(directionNum == NORTH) {
            if(boards[x][y] == 0) {
                //copy dice to board
                boards[x][y] = dice[BOTTOM];
            }
            else {
                //copy board to dice
                dice[BOTTOM] = boards[x][y];
                boards[x][y] = 0;
            }
            //update coordinate
            --x;
            if(x < 0) {
                ++x;
                continue;
            }
            else {
                //roll the dice
                swap(dice[TOP], dice[FRONT]);
                swap(dice[FRONT], dice[BOTTOM]);
                swap(dice[BOTTOM], dice[BACK]);
                printf("%d\n",dice[TOP]);
            }
        }
        else if(directionNum == SOUTH) {
            if(boards[x][y] == 0) {
                //copy dice to board
                boards[x][y] = dice[BOTTOM];
            }
            else {
                //copy board to dice
                dice[BOTTOM] = boards[x][y];
                boards[x][y] = 0;
            }
            //update coordinate
            ++x;
            if(x >= row) {
                --x;
                continue;
            }
            else {
                //roll the dice
                swap(dice[TOP], dice[BACK]);
                swap(dice[BACK], dice[BOTTOM]);
                swap(dice[BOTTOM], dice[FRONT]);
                printf("%d\n",dice[TOP]);
            }
        }   
    }
    return 0;
}