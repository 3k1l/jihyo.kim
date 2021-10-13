#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int arr[51][51];
int n, l, r;

vector<pair<int, int> > bfs(int y, int x, bool checked[51][51] ) {
    queue<pair<int, int> > q;
    bool GO = false;
    checked[y][x] =true;
    q.push(make_pair(y,x));
    vector<pair<int, int> > v;
    while(!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        v.push_back(make_pair(curY, curX));
        for(int i = 0 ; i < 4 ; ++i) {
            for(int j = 0; j < 4 ; ++j) {
                int newX = curX + dx[i];
                int newY = curY + dy[i];
                if(newX < 0 || newX >= n ||newY < 0 || newY >= n)
                    continue;
                if(checked[newY][newX]) {
                    continue;
                }
                int gap = arr[curY][curX] - arr[newY][newX];
                if(gap < 0) {
                    gap = -gap;
                }
                if(gap >= l && gap <= r) {
                    GO = true;
                    q.push(make_pair(newY, newX));
                    checked[newY][newX] = true;
                }
            }
        }
    }
    return v;
}


int main() {
    cin >> n >> l >> r;
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < n ; ++j) {
            cin >> arr[i][j];
        }
    }
    //first step
    int day = 0;
    bool GO_NEXT;
    while(true) {
        GO_NEXT = false;
        bool checked[51][51]={false};
        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < n ; ++j) {
                if(!checked[i][j]) {
                    vector<pair<int, int> > v ;
                    int sum, avg;
                    avg = sum = 0;
                    v = bfs(i, j, checked);
                    // get value
                    for(int k = 0 ;  k  < v.size() ;++k) {
                        sum += arr[v[k].first][v[k].second];
                    }
                    if(v.size() > 1) {
                        avg = sum / v.size();
                        // update value
                        for(int k = 0 ; k < v.size(); ++k) {
                            arr[v[k].first][v[k].second] = avg;
                        }
                        GO_NEXT = true;
                    }
                    v.clear();
                }
            }
        }
        if(GO_NEXT)
            ++day;
        else 
            break;
    }
    cout<< day << endl;
    return 0;
}