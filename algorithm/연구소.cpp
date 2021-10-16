#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0, 0, -1, 1};
int boards[9][9];
int n,m;
int totalOne = 3;

int bfs(int x, int y, bool checked[9][9], int game[9][9]) {
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    checked[x][y] = true;
    int num = 0;
    while(!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        ++num;
        for(int i = 0 ; i < 4 ; ++i) {
            int newX = curX + dx[i];
            int newY = curY + dy[i];
            if (newX <  0 || newX >= n || newY < 0 || newY >=m) {
                continue;
            }
            if (checked[newX][newY]) {
                continue;
            }
            if (game[newX][newY] == 1) {
                continue;
            }
            q.push(make_pair(newX,newY));
            checked[newX][newY] = true;
        }
    }
    return num;
}


int main() {
    int result = 0;
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < m ; ++j) {
            cin >> boards[i][j];
            if(boards[i][j] == 1)
                ++totalOne;
        }
    }
    //make wall
    int temp[9][9];
    vector<bool> permutation(n*m - 3, false);
    permutation.insert(permutation.end(), 3, true);
    vector<pair<int, int> > wall;
    int cnt = 0;

    do{
        bool makewall = true;
        wall.clear();
        for(int i = 0 ; i < permutation.size(); ++i) {
            if(permutation[i]) {
                int row = i / m;
                int col = i % m;
                //if it's wall or virus. go next perm
                if(boards[row][col] == 1  || boards[row][col] == 2) {
                    makewall = false;
                    break;
                }
                //check wall
                wall.push_back(make_pair(row, col));
            }
        }
        //make wall
        if(makewall) {
            bool wallChecked[9][9]={false};
            for(int j = 0 ; j < n ; ++j) {
                for(int k = 0; k < m ; ++k) {
                    temp[j][k] = boards[j][k];
                    wallChecked[j][k] = false;
                }
            }
            for(int i = 0 ; i < wall.size(); ++i) {
                temp[wall[i].first][wall[i].second] = 1 ;
            }
            //check value
            //count answer
            int num = 0;
            int totalNum = 0;
            int oneCount = n*m;
            for(int i = 0 ; i < n ; ++i) {
                for(int j = 0 ; j < m ; ++j) {
                    if(boards[i][j] == 2) {
                        if(!wallChecked[i][j]) {
                            num = bfs(i,j, wallChecked, temp);
                            totalNum += num;
                            //cout<<totalNum << endl;
                        } 
                    }
                }
            }
            //cout<<totalNum<<endl;
            oneCount = oneCount - totalNum - totalOne;
            if(oneCount > result) {
                result = oneCount;
            }
        }
    }while(next_permutation(permutation.begin(), permutation.end()));

    //result
    cout<< result<<endl;
    return 0;
}