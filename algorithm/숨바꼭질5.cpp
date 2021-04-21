#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = 500001;
int subinsLocation[500001] = {500001};
int visited[500001][2];
/*
int cacl(int location_subin, int second) {
    int curSubin = location_subin;
    for(int i = 0 ; i <= second ; ++i)
        curSubin += i;
    return curSubin;
}
*/
void go(int location_sister,int location_subin, int second) {
    queue<pair<int, int> > q;
    q.push(make_pair(location_sister, second));
    int curSister, curSecond, curSubin;
    while(!q.empty()) {
        curSister = q.front().first;
        curSecond = q.front().second;
        //curSubin =  cacl(location_subin, curSecond);
        curSubin =  subinsLocation[curSecond];
        q.pop();
        if(visited[curSister][curSecond%2] != -1)
            continue;
        visited[curSister][curSecond%2] = curSecond;
        cout<<curSister<<" "<<curSubin<<" "<<curSecond<<endl;
        if(curSubin > 500000) {
            continue;
        }
        if(curSister == curSubin) {
            cout<<curSecond<<endl;
            answer = min(answer, curSecond);
            continue;
        }
        if(answer <= curSecond) {
            continue;
        }
        //add next
        if(curSister > 0) {
            //if(visited[curSister-1] == -1 || (visited[curSister-1] != -1 && visited[curSister-1] > curSecond+1)) {
                q.push(make_pair(curSister-1, curSecond+1));
                //visited[curSister-1] = curSecond;
            //}
        }
        if(curSister < 500000) {
            //if(visited[curSister+1] == -1 || (visited[curSister+1] != -1 && visited[curSister+1] > curSecond+1)) {
                q.push(make_pair(curSister+1, curSecond+1));
                //visited[curSister+1] = curSecond;
            //}
        }
        if(curSister <= 250000) {
            //if(visited[curSister*2] == -1 || (visited[curSister*2] != -1 && visited[curSister*2] > curSecond+1)) {
                q.push(make_pair(curSister*2, curSecond+1));
                //visited[curSister*2] = curSecond;
            //}
        }
    }
}

int main() {
    int location_subin, location_sister;
    int second = 0;
    scanf("%d %d", &location_sister, &location_subin);
    //go to find answer
    
    subinsLocation[0] = location_subin;
    visited[0][0] = -1;
    visited[0][1] = -1;

    for(int i = 1 ; i < 500001 ; ++i) {
        subinsLocation[i] = subinsLocation[i-1] + i;
        visited[i][0] = -1;
        visited[i][1] = -1;

    }

    go(location_sister, location_subin, second);

    if(answer == 500001)
        answer = -1;
    printf("%d \n", answer);
    return 0;
}