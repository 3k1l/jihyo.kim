#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX_NUM 1000

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int land[][MAX_NUM], bool visited[][MAX_NUM], int row, int col) {
    queue<pair<int, int> > inputQ;
    inputQ.push(make_pair(row, col));
    visited[row][col] = true;
    int x, y;
    pair<int, int> val;
    while(!inputQ.empty()) { 
        val = inputQ.front();
        x = val.first;
        y = val.second;
        inputQ.pop();
        for(int i = 0 ; i < 4 ; i++) {
                if(land[x + dx[i]][y + dy[i]] == 1 && !visited[x + dx[i]][y + dy[i]]) {
                    inputQ.push(make_pair(x + dx[i],y + dy[i]));
                    visited[x + dx[i]][y + dy[i]] = true;
                }
            
        }
    }
}

void solution(int land[][MAX_NUM], int row, int col, int location, vector<pair<int, int> > worm) {
    bool visited[MAX_NUM][MAX_NUM] = {false};
    int answer = 0;
    for(pair<int, int> tmp : worm) {
         if(!visited[tmp.first][tmp.second]) {
            bfs(land, visited, tmp.first, tmp.second);
            ++answer;
        }
    }
    cout << answer << endl;
    /*
    for(int i = 0 ; i < row ; ++i ) {
        for(int j = 0 ; j < col ; ++j) {
            if(!visited[i][j] && land[i][j] == 1)
                bfs();
        }
    }
    */
}

int main() {
    int tc, row, col, location;
    int land[MAX_NUM][MAX_NUM];
    int row_t, col_t;
    vector<pair<int, int> > worm;

    scanf("%d", &tc);
    for(int j = 0 ; j < tc ; ++j) {
        worm.clear();
        scanf("%d", &row);
        scanf("%d", &col);
        scanf("%d", &location);
        memset(land, 0, sizeof(land));
        for(int i = 0 ; i < location ; ++i) {
            scanf("%d", &row_t);
            scanf("%d", &col_t);
            land[row_t][col_t] = 1;
            worm.push_back(make_pair(row_t, col_t));
        }
        solution(land, row, col, location, worm);
    }
    return 0;
}