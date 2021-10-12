#include <iostream>
#include <queue>
using namespace std;
int n,m;
int boards[51][51];
int answer = 0;
int dx[8] = {0, 0, -1, 1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};

struct Point{
    int x;
    int y;
    int num;
};

int bfs(int x, int y) {
    bool visited[51][51] = {false};
    queue<Point> q;
    Point point;
    point.x = x;
    point.y = y;
    point.num = 0;
    q.push(point);
    visited[x][y] =true;
    int result = 51;
    while(!q.empty()) {
        point = q.front();
        q.pop();
        int curX = point.x;
        int curY = point.y;
        int curNum = point.num;
        if(boards[curX][curY] == 1) {
            if(result > curNum) {
                result = curNum;
            }
        }
        for(int i = 0 ; i < 8 ; ++i) {
            Point newPoint;
            int newX, newY;
            newX = curX + dx[i];
            newY = curY + dy[i];
            if(newX < 0 || newX >= n || newY < 0 || newY >= m) {
                continue;
            }
            if(visited[newX][newY]) {
                continue;
            }
            newPoint.x = newX;
            newPoint.y = newY;
            newPoint.num = curNum + 1;
            q.push(newPoint);
            visited[newX][newY] = true;
        }
    }
    return result;
}
int main() {
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < m ; ++j) {
            cin >> boards[i][j] ;
        }
    }
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < m ; ++j) {
            if(boards[i][j] == 0) {
                int result = bfs(i, j);
                answer = max(result, answer);
            }
        }
    }
    cout<< answer << endl;
    return 0;
}