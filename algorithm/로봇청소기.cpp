#include<iostream>
using namespace std;

enum direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

enum ways {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

//left, right, up, down
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void turn(int ** boards, int x, int y, int d, int way) {

}

int main() {
    int N, M;
    int x, y, d;
    int cleanNum = 0;
    bool blocked = true;
    scanf("%d %d", &N, &M);
    scanf("%d %d %d",&x, &y, &d);
    //malloc boards
    int **boards = new int*[N];
    int **visited = new int*[N];
    for(int i = 0; i < N ; ++i) {
        boards[i] = new int[M];
        visited[i] = new int[M];
    }
    //initialize boards
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < M ; ++j) {
            scanf("%d",&boards[i][j]);
            if(boards[i][j] == 0)
                visited[i][j] = 0;
            else
                visited[i][j] = 1;
        }
    }
    //solution
    while(true) {
        blocked = true;
        if(visited[x][y] == 0)
            ++cleanNum;
        //check 4 way is blocked
        for(int i = 0 ; i < 4 ; ++i) {
            if(visited[x+dx[i]][y+dy[i]] == 0 && boards[x+dx[i]][y+dy[i]] == 0) {
                blocked = false;
                break;
            }
        }
        if(blocked) {
            //back and go to second step
            
        }
        else {

        }
    }
    //free boards
    for(int i = 0; i < N ; ++i) {
        delete[] boards[i];
        delete[] visited[i];
    }
    delete[] boards;
    delete[] visited;
}