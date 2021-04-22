#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = 500001;
int visited[500001][2];

void go(int location_sister,int location_subin ) {
    queue<pair<int, int> > q;
    q.push(make_pair(location_sister, 0));
    int curSister, curSecond, curSubin;
    visited[location_sister][0] = true;
    while(!q.empty()) {
        curSister = q.front().first;
        curSecond = q.front().second;
        curSubin =  location_subin + curSecond*(curSecond+1)/2;
        q.pop();
        if(curSubin > 500000) {
            break;
        }
        if(curSister == curSubin || visited[curSubin][curSecond%2]) {
            answer = min(answer, curSecond);
            break;
        }
        int nextSecond = curSecond +1;
        if(curSister > 0) {
            if(!visited[curSister-1][nextSecond%2]) {
                q.push(make_pair(curSister-1, curSecond+1));
                visited[curSister-1][nextSecond%2] = true;
            }
        }
        if(curSister < 500000) {
            if(!visited[curSister+1][nextSecond%2]) {
                q.push(make_pair(curSister+1, curSecond+1));
                visited[curSister+1][nextSecond%2] = true;
            }
        }
        if(curSister <= 250000) {
            if(!visited[curSister*2][nextSecond%2]) {
                q.push(make_pair(curSister*2, curSecond+1));
                visited[curSister*2][nextSecond%2] = true;
            }
        }
    }
}

int main() {

    int location_subin, location_sister;
    scanf("%d %d", &location_sister, &location_subin);
    //go to find answer

    go(location_sister, location_subin);

    if(answer == 500001)
        answer = -1;
    printf("%d \n", answer);
    return 0;
}