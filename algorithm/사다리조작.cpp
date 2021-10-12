#include <iostream>

using namespace std;

int h,n,m = 0;

int visited[31][11] = {0};

int answer = 51;

bool checkBoards(int boards[31][11]) {
    bool answer = true;
    int position[11];

    for(int i = 1 ; i <= n ; ++i) {
        position[i] = i;
    }
    for(int i = 1 ; i <= h ; ++i) {
        for(int j = 1; j <= n ; ++j) {
            if(boards[i][j] == 1) {
                for(int k = 1; k <= n ; ++k) {
                    if(position[k] == j) {
                        position[k] = j+1;
                    }
                    else if(position[k] == j+1) {
                        position[k] = j;
                    }
                }
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i) {
        if(position[i] != i) {
            answer= false;
            break;
        }
    }

    return answer;
}
void dfs(int a, int depth,int boards[][11]) {
    int tempBoards[31][11];
    if(depth >= 4) {
        return;
    }

    for(int i = 1 ; i <= h ; ++i) {
        for(int j = 1 ; j <= n ;++j) {
            tempBoards[i][j] = boards[i][j];
        }
    }

    for(int i = a ; i <= h ; ++i) {
        for(int j = 1 ; j <= n ; ++j) {
            if(tempBoards[i][j] == 1) {
                continue;
            }
            if(j-1 > 0) {
                if(tempBoards[i][j-1]) {
                    continue;
                }
            }
            if(j+1 <= n) {
                if(tempBoards[i][j+1]) {
                    continue;
                }
            }
            tempBoards[i][j] = 1;
            if(checkBoards(tempBoards)) {
                answer = min(depth, answer);
                return;
            }
            else {
                dfs(i, depth+1, tempBoards);
            }
            tempBoards[i][j] = 0;
        }
    }
}

int main() {
    int boards[31][11] = {0};
    cin >> n >> m >> h;
    for(int i = 0 ; i < m ; ++i) {
        int a,b;
        cin >> a >> b;
        boards[a][b] = 1;
    }

    //do for 0
    if(checkBoards(boards)) {
        cout << "0"<< endl;
        return 0;
    }
    //dfs!
    dfs(0,1,boards);
    if(answer == 51) {
        answer = -1;
    }
    cout<<answer<<endl;
    return 0;
}