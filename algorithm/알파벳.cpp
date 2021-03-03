#include <vector>
#include <iostream>

#define MAX_NUM 20
#define ALPHABET_NUM 26
using namespace std;
static int dx[4] = {1, -1, 0, 0};
static int dy[4] = {0, 0, 1, -1};
int max_num = 0;
int row, col;

int dfs(int x, int y, char board[][MAX_NUM], bool visited[ALPHABET_NUM], int depth) {
    char alphabet = board[x][y];
    int num = alphabet - 'A';
    int answer = 0;
    
    if(visited[num] || x >= row || y >= col || x < 0 || y < 0) {
        return depth;
    }
    else {
        for(int i = 0; i < 4; ++i) {
            visited[num] = true;
            answer = dfs(x+dx[i], y+dy[i], board, visited, depth+1);
            max_num = max(max_num, answer);
            visited[num] = false;
        }
    }
    return max_num;
}

void solution(int row, int col, char board[][MAX_NUM]) {
    int answer = 0;
    bool visited[ALPHABET_NUM] = {false};
    answer = dfs(0, 0, board, visited, 0);
    cout<< answer;
}

int main() {
    char board[MAX_NUM][MAX_NUM];
    scanf("%d", &row);
    scanf("%d", &col);
    for(int i = 0 ; i < row ; ++i) {
        for(int j = 0 ; j < col ; ++j) {
            cin>>board[i][j];
        }          
    }
    solution(row, col, board);
    return 0;
}