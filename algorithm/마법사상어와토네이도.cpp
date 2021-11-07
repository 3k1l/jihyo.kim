#include<iostream>
#include <cmath>
using namespace std;
bool stop = false;
int curX, curY;
int answer = 0;
int map[500][500];
//left, down, right, up
int dy[4] = {0, 1, 0 ,-1};
int dx[4] = {-1, 0, 1, 0};

double port[5][5] = {
{0, 0, 0.02, 0, 0}, 
{0, 0.1, 0.07, 0.01, 0}, 
{0.05, 0.45, 0, 0, 0}, 
{0, 0.1, 0.07, 0.01, 0}, 
{0, 0, 0.02, 0, 0}};

int y,x,n;
int getLeftSand(int originalSand) { 
    return originalSand - floor(originalSand * 0.01) * 2 - floor(originalSand * 0.02) * 2 - floor(originalSand * 0.07) * 2 - floor(originalSand * 0.1) * 2 - floor(originalSand * 0.05); }

void blow(int dir) {
    int gone, goneTotal;
    gone = goneTotal = 0;
    int original = map[y][x];
    if(map[y][x] == 0) {
        return;
    }
    for(int i = -2 ; i <= 2; ++i) {
        for(int j = -2 ; j <=2 ; ++j) {
            int newY, newX;
            newY = y + i;
            newX = x + j;
            if(port[i+2][j+2] == 0) {
                continue;
            }
            if(port[i+2][j+2] < 0.4 ) {
                gone = floor(original * port[i+2][j+2]);
                //cout<<gone<<endl;
            }
            else {
                gone = getLeftSand(original);
                //cout<<gone<<endl;
            }
            if(newY < 0 || newY >= n || newX < 0 || newX >= n) {
                //cout<<gone<<endl;
                answer += gone;
            }
            else {
                map[newY][newX] += gone;
            }
        }
    }

    map[y][x] = 0;
}

void move(int dir) {
    y = y + dy[dir];
    x = x + dx[dir];

    if(y < 0 || y >= n || x < 0 || x>=n) {
        cout<<"sth wrong... y "<<y<<" x "<<x<<endl;
    }
}

void rotate() {
    double temp[5][5];
    for(int i  = 0 ; i < 5 ; ++i) {
        for(int j = 0 ; j < 5 ; ++j) {
            temp[i][j] = port[i][j];
        }
    }
    for(int i  = 0 ; i < 5 ; ++i) {
        for(int j = 0 ; j < 5 ; ++j) {
            port[5-j-1][i] = temp[i][j];
        }
    }
}

int main() {
    int  cnt, goCnt, dir;
    cin >> n;
    for(int i  = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < n ; ++j) {
            cin >> map[i][j];
        }
    }
    y = (n)/2;
    x = (n)/2;
    goCnt = 1;
    dir = 0;
    while(true) {
        if(y == 0 && x == 0) {
            break;
        }
        for(int j = 0 ; j < 2; ++j) {
            for(int i = 0 ; i < goCnt ;++i) {
                move(dir);
                //cout<<"now : "<<y<<" "<<x<<endl;
                blow(dir);
                if(y == 0 && x == 0) {
                    cout<<answer<<endl;
                    return 0;
                }
            }
            dir = (dir == 3) ? 0 : dir + 1;
            rotate();
        }
        ++goCnt;
    }
    cout<< answer<< endl;
    return 0;
}