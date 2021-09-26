#include <iostream>
#include <queue>

using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int main() {
    int babyX, babyY, babySize, eatCnt, N, distance, minDistance, targetX, targetY, time;
    bool eat = false;
    scanf("%d",&N);
    int boards[N][N];
    //initialize
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < N ; ++j) {
            scanf("%d", &boards[i][j]);
            if(boards[i][j] == 9) {
                babyX = i;
                babyY = j;
                boards[i][j] = 0;
            }
        }
    }
    babySize = 2;
    eatCnt = 0;
    time = 0;
    queue<pair<int,int> > q;
    q.push(make_pair(babyX, babyY));
    int x,y, curx, cury;
    while(!q.empty()) {
        curx = q.front().first;
        cury = q.front().second;
        q.pop();
        if(boards[curx][cury] < babySize) {
            //you can eat
            ++eatCnt;
            curx = 0;
            cury = 0;
        }
        else if(boards[curx][cury] == babySize) {
            //just move

        }
        if(eatCnt == babySize) {
            ++babySize;
            eatCnt = 0;
        }
        for(int i = 0 ; i < 4 ; ++i) {
            x = curx+ dx[i];
            y = cury + dy[i];
            if(boards[x][y] <= babySize) {
            //you can eat
                q.push(make_pair(x,y));
            }
            //else if(boards[x][y] == babySize) {
            //you can pass through

            //}
        }
    }
    /*
    //go
    while(true) {
        eat = false;
        minDistance = 2*N;
        distance = 0;
        //try to find pray
        for(int dx = 0 ; dx < N ; ++dx) {
            for(int dy = 0 ; dy < N ; ++dy) {
                if(boards[dx][dy] == 0)
                    continue;
                if(boards[dx][dy] < babySize) {
                    distance = abs(babyX - dx) + abs(babyY - dy);
                    if(!eat) {
                        targetX = dx;
                        targetY = dy;
                        minDistance = distance;
                        eat = true;
                    }
                    else {
                        if(minDistance > distance) {
                            minDistance = distance;
                            targetX = dx;
                            targetY = dy;
                        }
                        else if(minDistance == distance) {
                            //if same, check upper(means smaller dx)
                            if(dx < targetX) {
                                targetX = dx;
                                targetY = dy;
                            }
                            else if(dx == targetX){
                                //if same, check left(means smaller dy)
                                if(dy < targetY) {
                                    targetX = dx;
                                    targetY = dy;
                                }
                            }
                        }
                    }
                } 
            }
        }
        //success to find
        if(eat) {
            //then move baby shark
            time = time + abs(targetX - babyX) + abs(targetY - babyY);
            babyX = targetX;
            babyY = targetY;
            eatCnt++;
            boards[targetX][targetY]  = 0;
            cout<<"x : "<< targetX <<" y : " << targetY<<" time : "<<time <<" eat : "<<eatCnt<< " baby : "<<babySize <<endl;
        }
        else {
            break;
        }
        //check size up the baby shark
        if(eatCnt == babySize) {
            ++babySize;
            eatCnt = 0;
        }
    }
    */
    cout<<time<<endl;
    return 0;
}