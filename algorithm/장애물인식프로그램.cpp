#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_NUM 26
int boards[MAX_NUM][MAX_NUM];
int visited[MAX_NUM][MAX_NUM] = {false};
int dx[4] = {1, -1 ,0 , 0};
int dy[4] = {0, 0 , -1, 1};
int num;

int dfs(int x, int y) {
    int cnt = 0;
    int cur_x, cur_y;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    while(!q.empty()) {
        cur_x = q.front().first;
        cur_y = q.front().second;
        q.pop();
        ++cnt;
        for(int i = 0 ; i < 4 ; ++i) {
            int new_x, new_y;
            new_x = cur_x+dx[i];
            new_y = cur_y+dy[i];
            if((new_x) >= 0 && (new_x) < num && (new_y) >= 0 && (new_y) < num) {
                if(!visited[new_x][new_y] && (boards[new_x][new_y] == 1)) {
                    visited[new_x][new_y] = true;
                    q.push(make_pair(new_x, new_y));
                }
            }
        }
    } 
    return cnt;
}

int main(int argc, char** argv) {
    cin >> num;
    string inputRow;
    vector<int> countBlock;
    //initialize
    for(int i = 0 ; i < num ; ++i ) {
        cin >> inputRow;
        for(int j  = 0 ; j < num ; ++j) {
            char tmp = inputRow[j];
            boards[i][j] = (int) tmp - '0';
        }
    }
    

    for(int i = 0 ; i < num ; ++i ) {
        for(int j = 0 ; j < num ; ++j) {
            cout<<boards[i][j] << "dd ";
            if(!visited[i][j]) {
                //num = dfs(i, j);
                countBlock.push_back(num);
            }
        }
        cout <<endl;
    }
    sort(countBlock.begin(), countBlock.end());
    for(int i : countBlock) {
        cout <<"nn "<< i << endl;
    }
    return 0;
}