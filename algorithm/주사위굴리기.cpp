#include <iostream>
#include <vector>

using namespace std;

enum direction {
    EAST, WEST, NORTH, SOUTH
};
enum side{
    TOP, FRONT ,BOTTOM, BACK, LEFT, RIGHT
};
int main() {
    int row, col, x, y, num, directionNum;
    scanf("%d %d %d %d %d", &row, &col, &x, &y, &num);
    int boards[20][20];
    vector<int> dice(6);
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
            }
            //update coordinate
            //East ++y
            ++y;
            if(y >= col) {
                --y;
                cout<<directionNum<<" x : "<<x<<" y : "<<y <<"\n";
                continue;
            }
            else {
                //roll the dice
                swap(dice[TOP], dice[LEFT]);
                swap(dice[BOTTOM], dice[RIGHT]);
                swap(dice[LEFT], dice[RIGHT]);
                cout<<dice[TOP]<<"\n";
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
            }
            //update coordinate
            --y;
            if(y < 0) {
                ++y;
                cout<<directionNum<<" x : "<<x<<" y : "<<y <<"\n";
                continue;
            }
            else {
                //roll the dice
                swap(dice[TOP], dice[RIGHT]);
                swap(dice[BOTTOM], dice[LEFT]);
                swap(dice[LEFT], dice[RIGHT]);
                cout<<dice[TOP]<<"\n";
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
            }
            //update coordinate
            --x;
            if(x < 0) {
                ++x;
                cout<<directionNum<<" x : "<<x<<" y : "<<y <<"\n";
                continue;
            }
            else {
                //roll the dice
                swap(dice[TOP], dice[FRONT]);
                swap(dice[FRONT], dice[BOTTOM]);
                swap(dice[BOTTOM], dice[BACK]);
                cout<<dice[TOP]<<"\n";
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
            }
            //update coordinate
            ++x;
            if(x >= row) {
                --x;
                cout<<directionNum<<" x : "<<x<<" y : "<<y <<"\n";
                continue;
            }
            else {
                //roll the dice
                swap(dice[TOP], dice[BACK]);
                swap(dice[BACK], dice[BOTTOM]);
                swap(dice[BOTTOM], dice[FRONT]);
                cout<<dice[TOP]<<"\n";
            }
        }   
    }
    return 0;
}