#include <iostream>

using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int boards[500][500];
int visited[500][500];
int resultMax = 0;
int n, m;

void findFuck(int x, int y) {
    //ㅜ
    if(x+1 < n && y+2 < m) {
        resultMax = max(resultMax, boards[x][y] + boards[x][y+1] + boards[x][y+2] + boards[x+1][y+1]);
    }
    //ㅗ
    if(x-1 >= 0 && y+2 < m) {
        resultMax = max(resultMax, boards[x][y] + boards[x][y+1] + boards[x][y+2] + boards[x-1][y+1]);
    }
    //ㅓ
    if(x+2 < n && y-1 >= 0) {
        resultMax = max(resultMax, boards[x][y] + boards[x+1][y] + boards[x+2][y] + boards[x+1][y-1]);
    }
    //ㅏ
    if(x+2 < n && y+1 < m) {
        resultMax = max(resultMax, boards[x][y] + boards[x+1][y] + boards[x+2][y] + boards[x+1][y+1]);
    }
}

void findNormal(int depth, int x, int y, int temp) {
    if(depth >=3) {
        resultMax = max(resultMax, temp);
        return;
    }
    for(int i = 0 ; i < 4 ; ++i) {
        int newX,newY;
        newX = x + dx[i];
        newY = y + dy[i];
        if(newX >= 0 && newX < n && newY >= 0 && newY < m) {
            if(!visited[newX][newY]) {
                visited[newX][newY] = true;
                findNormal(depth+1, newX, newY, temp + boards[newX][newY]);
                visited[newX][newY] = false;
            }
        }
    }
}

void dfs(int x, int y) {
    findFuck(x ,y);
    visited[x][y] = true;
    findNormal(0, x, y, boards[x][y]);
    visited[x][y] = false;
}

int main() {
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < m ;++j) {
            cin >> boards[i][j];
        }
    }
    for(int i = 0 ; i< n ; ++i) {
        for(int j = 0 ; j < m ; ++j) {
            dfs(i,j);
        }
    }
    cout << resultMax << endl;
    return 0;
}