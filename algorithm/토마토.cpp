#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define MAXNUM 1000

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int tomato[MAXNUM][MAXNUM];
int days[MAXNUM][MAXNUM];
int minDays = MAXNUM;
int n, m;
queue<pair<int, int>> q ;

int bfs() {
    int visited[MAXNUM][MAXNUM] = {0,};
    int day = 0;

    while(!q.empty()) {
        pair<int, int> node = q.front();
        int nodeRow = node.first;
        int nodeCol = node.second;
        visited[nodeRow][nodeCol] = 1;
        day = max(day, days[nodeRow][nodeCol]);
        q.pop();
        for(int i = 0 ; i < 4 ; ++i) {
            int curRow = nodeRow + dx[i];
            int curCol = nodeCol + dy[i];
            if(curRow >= 0 && curRow < m && curCol >= 0 && curCol < n && visited[curRow][curCol] == 0 && tomato[curRow][curCol] == 0) {
               // if(days[curRow][curCol] == -1 || days[curRow][curCol] > days[nodeRow][nodeCol] + 1) {
                    days[curRow][curCol] = days[nodeRow][nodeCol] + 1;
              //  }
                visited[curRow][curCol] = 1;
                q.push(make_pair(curRow, curCol));
            }
        }
    }
    return day;
}

int main() {
    cin >> n >> m ;
    for(int i = 0 ; i < m ; ++i) {
        for(int j = 0 ; j< n; ++j) {
            scanf("%d", &tomato[i][j]);
            days[i][j] = 0;
            if(tomato[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }

    int day = bfs();
    for(int i = 0 ; i < m ; ++i) {
        for(int j = 0 ; j< n; ++j) {
            if(tomato[i][j] == 0 && days[i][j] == 0) {
                cout << "-1";
                return 0;
            }
        }
    }
    cout << day;
    return 0;
}