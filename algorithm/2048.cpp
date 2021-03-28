#include <iostream>
#include <vector>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGTH 3

using namespace std;
int answer = 0;

void findMax(int board[20][20], int boardRow) {
    for(int i = 0 ; i < boardRow ; ++i) {
        for(int j = 0 ; j < boardRow ; ++j) {
            answer= max(answer, board[i][j]);
        }
    }
    cout<<"findMax : "<< answer<<'\n';
}

void moveBlock(int board[20][20], int boardRow, int cnt, int way) {
    int boardTemp[20][20];
    int row,col;
    row = col = 0;
    //end point
    if(cnt == 0) {
        findMax(board, boardRow);
        return;
    }

    if(way == UP) {
        //initialize
        row = 0; 
        for(int i = 0 ; i < boardRow ; ++i) {
            for(int j = 0 ; j < boardRow; ++j) {
                boardTemp[i][j] = board[i][j];
            }
        }
        //move point
        for(int i = 0 ; i < boardRow ; ++i) {
            for(int j = 0 ; j < boardRow ; ++j) {
                //check below board is same
                if(board[i][j] == 0) 
                    continue;
                
                if(i < boardRow-1) {
                    if(board[i+1][j] == board[i][j]) {
                        board[i][j] *= 2;
                        board[i+1][j] = 0;
                        continue;
                    }
                }
                if(board[row][j] == 0) {
                    board[row][j] = board[i][j];
                    board[i][j] = 0;
                }
            }
        }
        //call to next step
        for(int i = 0 ; i < 4 ; ++i) {
            moveBlock(boardTemp, boardRow, cnt-1, i);
        }
    }
    else if(way == DOWN) {
        for(int i = 0 ; i < boardRow ; ++i) {
            for(int j = 0 ; j < boardRow; ++j) {
                boardTemp[i][j] = board[i][j];
            }
        }
        for(int i = 0 ; i < 4 ; ++i) {
            moveBlock(boardTemp, boardRow, cnt-1, i);
        }
    }
    else if(way == LEFT) {
        for(int i = 0 ; i < boardRow ; ++i) {
            for(int j = 0 ; j < boardRow; ++j) {
                boardTemp[i][j] = board[i][j];
            }
        }
        for(int i = 0 ; i < 4 ; ++i) {
            moveBlock(boardTemp, boardRow, cnt-1, i);
        }
    }
    else if(way == RIGTH) {
        for(int i = 0 ; i < boardRow ; ++i) {
            for(int j = 0 ; j < boardRow; ++j) {
                boardTemp[i][j] = board[i][j];
            }
        }
        for(int i = 0 ; i < 4 ; ++i) {
            moveBlock(boardTemp, boardRow, cnt-1, i);
        }
    }
    
}

void solution(int board[20][20], int boardRow) {
    int cnt = 5;
    int num;

    for(int i = 0 ; i < 4 ; ++i) {
        moveBlock(board, boardRow, cnt, i);//way == i 
    }
}

int main() {
    int boardRow;
    int board[20][20] = {0};
    scanf("%d", &boardRow );
    for(int i = 0 ; i < boardRow ; ++i) {
        for(int j = 0 ; j < boardRow; ++j) {
            scanf("%d", &board[i][j]);
        }
    }
    cout<<answer;
    return 1;
}