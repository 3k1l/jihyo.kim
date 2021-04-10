#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int **boards, int **visted, int height, int x, int y, int n) {
    queue<pair<int, int> > q;
    visted[x][y] = true;
    q.push(make_pair(x,y));
    pair<int, int> node;
    while(!q.empty()) {
        node = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; ++i) {
            int nextX = node.first + dx[i];
            int nextY = node.second + dy[i];
            if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
                if(visted[nextX][nextY] == false) {
                    visted[nextX][nextY] = true;
                    if(boards[nextX][nextY] > height) {
                        q.push(make_pair(nextX, nextY));
                    }
                }
            }
        }
    }
    return;
}

int main() {
    int n;
    int maxHeight = 0;
    int result = 0;
    int cnt = 0 ;

    scanf("%d", &n);
    int **boards = new int*[n];
    int **visited = new int*[n];
    for(int i = 0 ; i < n ; ++i) {
        boards[i] = new int[n];
        visited[i] = new int[n];
        for(int j = 0 ; j < n ; ++j) {
            scanf("%d", &boards[i][j]);
            maxHeight = max(maxHeight, boards[i][j]);
        }
    }
    for(int height = 0 ; height < maxHeight; ++height) {
        for(int k = 0 ; k < n ; ++k)
            memset(visited[k], false, sizeof(int)*n);
        cnt = 0;
        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < n ; ++j) {
                if(visited[i][j] == false) {
                    if(boards[i][j] > height) {
                        bfs(boards, visited, height, i, j, n);
                        ++cnt; 
                    }
                }
            }
        }
        result = max(result, cnt);
    }
    printf("%d\n", result);

    for(int i = 0 ; i < n ; ++i) {
        delete[] boards[i];
        delete[] visited[i];
    }
    delete[] boards;
    delete[] visited;
    return 0;
}