#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int n,m;
int board[101][101];
int visited[101][101] ={0, };

void bfs(int row, int col) {
    queue<pair<int,int>> q;
    q.push(make_pair(row, col));
    while(!q.empty()) {
        pair<int,int> cur = q.front();
        int cur_x = cur.first;
        int cur_y = cur.second;
        q.pop();
        visited[cur_x][cur_y] = 1;
        if(cur_x+1 < n && board[cur_x+1][cur_y] == 1 && visited[cur_x+1][cur_y] == 0) {
            q.push(make_pair(cur_x+1, cur_y));
            board[cur_x+1][cur_y] = board[cur_x][cur_y] + 1;
        }
        if(cur_x > 0 && board[cur_x-1][cur_y] == 1 && visited[cur_x-1][cur_y] == 0) {
            q.push(make_pair(cur_x-1, cur_y));
            board[cur_x-1][cur_y] = board[cur_x][cur_y] +1;
        }
        if(cur_y+1 < m && board[cur_x][cur_y+1] == 1 && visited[cur_x][cur_y+1] == 0) {
            q.push(make_pair(cur_x, cur_y+1));
            board[cur_x][cur_y+1] = board[cur_x][cur_y] +1;
        }
        if(cur_y > 0 && board[cur_x][cur_y-1] == 1 && visited[cur_x][cur_y-1] == 0) {
            q.push(make_pair(cur_x, cur_y-1));
            board[cur_x][cur_y-1] = board[cur_x][cur_y] +1;
        }
    }
}

int main() {
    int input;
    cin >> n >> m;

    for(int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < m ; ++j) {
            scanf("%1d",&board[i][j]);
        }
    }
    bfs(0 ,0);
    cout<< board[n-1][m-1];
    return 0;
}