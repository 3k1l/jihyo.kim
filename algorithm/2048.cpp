#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0,0,-1,1}; //UP, DOWN, LEFT, RIGTH
int dy[4] = {-1,1,0,0}; //UP, DOWN, LEFT, RIGTH

int solution(int board[20][20]) {
    int answer = 0;


    return answer;
}

int main() {
    int boardRow;
    int board[20][20];
    scanf("%d", &boardRow );
    for(int i = 0 ; i < boardRow ; ++i) {
        for(int j = 0 ; j < boardRow; ++j) {
            scanf("%d", &board[i][j]);
        }
    }
    cout<<solution(board);
    return 1;
}