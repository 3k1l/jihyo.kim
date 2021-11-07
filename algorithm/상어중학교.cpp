#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stdio.h>

using namespace std;
int n,m;
int boards[25][25];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool R_Visit[25][25];
bool visited[25][25];

int answer = 0;

struct Info {
    vector<pair<int, int> > v;
    int rainbowCount;
    int col;
    int row;
    vector<pair<int, int> > rainbow;
};

void print() {
    cout<<endl;
    for(int i  = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < n ; ++j) {
            cout << boards[i][j]<<" ";
        }
        cout<<endl;
    };
    cout<<endl;
}

void gravity() {
    for(int i  = n-1 ; i >= 0 ; --i) {
        for(int j = 0 ; j < n ; ++j) {
            if(boards[i][j] == -1) {
                continue;
            }
            if(boards[i][j] == -2) {
                continue;
            }
            for(int k = i+1 ; k < n ; ++k) {
                if(boards[k][j] == -2) {
                    boards[k][j] = boards[k-1][j];
                    boards[k-1][j] = -2;
                }
                else {
                    break;
                }
            }
        }
    }
}

void rotate() {
    int temp[21][21];
    for(int i = 0 ; i < n ;++i) {
        for(int j = 0 ; j < n ; ++j) {
            temp[i][j] = boards[i][j];
        }
    }
    for(int col = n-1 ; col >= 0 ; --col) {
        for(int row = 0 ; row < n ; ++row) {
            boards[n-1-row][col] = temp[col][row];
        }
    }   
}

Info bfs(int y, int x, bool visited[25][25]) {
    memset(R_Visit, false, sizeof(R_Visit));
    Info info;
    queue<pair <int, int> > q;
    vector<pair <int, int> > v;
    int targetColor = boards[y][x];
    int targetX, targetY;
    targetX = x;
    targetY = y;
    q.push(make_pair(y,x));
    visited[y][x] = true;
    v.push_back(make_pair(y, x));
    int rainbowCount = 0;
    //cout<<"t "<<targetColor<<endl;
    while(!q.empty()) {
        int curX, curY;
        curX = q.front().second;
        curY = q.front().first;
        q.pop();
        if(boards[curY][curX] != 0) {
            if(curY < targetY) {
                targetY = curY;
                targetX = curX;
            }
            else if(curY == targetY) {
                if(curX < targetX) {
                    targetY = curY;
                    targetX = curX;
                }
            }
        }
        
        for(int i = 0 ; i < 4; ++i) {
            int nextX, nextY;
            nextX = curX + dx[i];
            nextY = curY + dy[i];
            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) {
                continue;
            }
            if(boards[nextY][nextX] == -1 || boards[nextY][nextX] == -2) {
                continue;
            }
            if(boards[nextY][nextX] == targetColor) {
                if(!visited[nextY][nextX]) {
                    visited[nextY][nextX] = true;
                    q.push(make_pair(nextY, nextX));
                    v.push_back(make_pair(nextY, nextX));
                }
            }
            else if(boards[nextY][nextX] == 0) {
                if(!R_Visit[nextY][nextX]) {
                    rainbowCount++;
                    R_Visit[nextY][nextX] = true;
                    q.push(make_pair(nextY, nextX));
                    v.push_back(make_pair(nextY, nextX));
                }
            }
        }
    }
    info.row = targetY;
    info.col = targetX;
    info.rainbowCount = rainbowCount;
    info.v = v;
    return info;
}

Info autoPlay() {
    bool Go = false;
    memset(visited, false, sizeof(visited));
    Info target;
    target.col = 0;
    target.row = 0;
    target.rainbowCount = 0;
    bool first = true;
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < n ; ++j) {
            if(boards[i][j] == -1 || boards[i][j] == -2 || boards[i][j] == 0 ) {
                continue;
            }
            if(visited[i][j]) {
                continue;
            }
            Info info = bfs(i, j, visited);
            if(first) {
                target = info;
                Go = false;
                first =false;
            }
            else {
                Go = true;
            }
        
            if(Go) {
                if(target.v.size() <  info.v.size()) {
                    target = info;
                }
                else if(target.v.size() == info.v.size()) {
                    if(target.rainbowCount < info.rainbowCount) {
                        target = info;
                    }
                    else if(target.rainbowCount == info.rainbowCount) {
                        if(target.row < info.row) {
                            target = info;
                        }
                        else if(target.row == info.row) {
                            if(target.col < info.col) {
                                target = info;
                            }
                        }
                    }
                }
            }
        }
    }

    return target;  
}

void deleteGroup(Info target) {
    for(int i = 0 ; i < target.v.size() ; ++i) {
        int targetY = target.v[i].first;
        int targetX = target.v[i].second;
        boards[targetY][targetX] = -2;
    }
}

int main() {
    cin >> n >> m;
    for(int i  = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < n ; ++j) {
            cin >> boards[i][j];
        }
    }

    while(true) {
        Info targetInfo;
        targetInfo = autoPlay();
        if(targetInfo.v.size() < 2) {
            break;
        }
        //cout<<"col : "<<targetInfo.col <<" row : "<<targetInfo.row<<endl;
        deleteGroup(targetInfo);
        //cout<<"a"<<endl;
        //print();
        gravity();
        //cout<<"b"<<endl;
        //print();
        rotate();
        //cout<<"c"<<endl;
        //print();
        gravity();
        //cout<<"d"<<endl;
        //print();
        answer += targetInfo.v.size()*targetInfo.v.size();

    }

    cout<<answer<<endl;
    return 0;
}


