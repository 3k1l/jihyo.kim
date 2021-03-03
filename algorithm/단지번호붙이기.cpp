#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int apt[26][26] = {0,};
int direction[4][4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
bool finded[26][26] = {false,};
int aptCnt[26*26];
int n;

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x,y));
    int cnt = 0;
    finded[x][y] = true;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        int x = cur.first;
        int y = cur.second;
        q.pop();
        ++cnt;
        for(int i = 0 ; i < 4; i++) {
            int cur_x = x + direction[i][0];
            int cur_y = y + direction[i][1];
            if(cur_x >= 0 && cur_x < n && cur_y >= 0 && cur_y < n) {
                if(apt[cur_x][cur_y] == 1 && finded[cur_x][cur_y] == false) {
                    q.push(make_pair(cur_x, cur_y));
                    finded[cur_x][cur_y] = true;
                }
            }
        }

    }
    return cnt;
}


int main() {
    int idx = 0;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < n ; ++j) 
            scanf("%1d", &apt[i][j]);
    }
    
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < n ; ++j) {
            if(finded[i][j] == false && apt[i][j] == 1) {
                aptCnt[idx] = bfs(i, j);
                idx++;
            }
        }
    }
    
    cout<< idx<< "\n";
    sort(aptCnt, aptCnt + idx);
    for(int i =0 ; i <
     idx ; ++i) {
        cout << aptCnt[i] << "\n";
    }
    return 0;
}