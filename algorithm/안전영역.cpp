#include <stdlib.h>
#include <queue>
using namespace std;

int bfs(int boards[101][101], int height) {
    int result = 0;
    queue<int> q;
    bool visited[101][101] = {false};
    q.push(boards[0][0]);
    visited[0][0] = true;
    while(!q.empty()) {
        
    }
}

int main() {
    int n;
    int boards[101][101];
    int maxHeight = 0;
    int result = 0;

    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < n ; ++j) {
            scanf("%d", &boards[i][j]);
            maxHeight = max(maxHeight, boards[i][j]);
        }
    }
    for(int i = 0 ; i < maxHeight; ++i)
        result = max(result, bfs(boards, i));
    return 0;
}