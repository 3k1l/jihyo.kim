#include <iostream>
#include <cmath>
using namespace std;
int n;
int boards[21][21] = {0};
int info[401][4] = {0};

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

void place(int target) {
    //boards[i][j]
    int targetX, targetY;
    int maxFavorite, maxBlank;
    maxFavorite = maxBlank = 0;
    targetX = targetY = n+1;
    for(int i = 1; i <= n ; ++i) {
        for(int j = 1 ; j <= n ;++j) {
            int blank = 0;
            int favorite = 0;
            if(boards[i][j] != 0) {
                continue;
            }
            for(int k = 0 ; k < 4 ; ++k) {
                int newY, newX;
                newY = i + dy[k];
                newX = j + dx[k];
                if(newY <= 0 || newY > n || newX > n || newX <= 0 ) {
                    continue;
                }
                if(boards[newY][newX] == 0) {
                    ++blank;
                    continue;
                }
                for(int l = 0 ; l < 4 ; ++l) {
                    if(boards[newY][newX] == info[target][l]) {
                        ++favorite;
                        break;
                    }
                }
            } // end of finding dx dy
            //check blank count and favorite count
            if(maxFavorite < favorite) {
                maxFavorite = favorite;
                maxBlank = blank;
                targetX = j;
                targetY = i;
            }
            else if(maxFavorite == favorite) {
                if(maxBlank < blank) {
                    maxBlank = blank;
                    targetX = j;
                    targetY = i;
                }
                if(maxBlank == blank) {
                    if(targetY > i) {
                        targetY = i;
                        targetX = j;
                    }
                    else if(targetY == i) {
                        if(targetX > j) {
                            targetX = j;
                            targetY = i;
                        }
                    }
                }
            }
        }
    }// end for i
    boards[targetY][targetX] = target;
}

int main() {
    cin >> n;
    int answer = 0;
    for(int i = 0 ; i < pow(n,2) ; ++i) {
        int target;
        cin >> target;
        for(int i = 0 ; i < 4 ; ++i) {
            cin >> info[target][i];
        }
        place(target);
    }
    /*
    for(int i = 1 ; i <= n ;++i) {
        for(int j =1  ; j <= n ; ++j) {
            cout<<boards[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    //place person
    for(int i = 1 ; i <= n ; ++i) {
        for(int j = 1 ; j <=n ; ++j) {
            int target = boards[i][j];
            int total = 0;
            for(int k  = 0 ; k < 4; ++k) {
                int newY, newX;
                newY = i + dy[k];
                newX = j + dx[k];
                if(newX > n || newX <= 0 || newY > n || newY <= 0) {
                    continue;
                }
                for(int l = 0 ; l < 4 ; ++l) {
                    if(info[target][l] == boards[newY][newX]) {
                        ++total;
                        break;
                    }
                }
            }
            if(total > 0) {
                total--;
                answer += pow(10, total);
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}