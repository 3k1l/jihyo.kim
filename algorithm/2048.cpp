#include <iostream>
using namespace std;

int n;
int resultMax = 0;

void printBoards(int borards[20][20], bool merged[20][20]) {
    cout<< "merged"<< endl;
    for(int i = 0; i < n ; ++i) {
        for(int j = 0 ; j< n ; ++j) {
            cout << borards[i][j] << " ";
        }
        cout<< endl;
    }
}
int moveUp(int boards[20][20],bool merged[20][20]) {
    int MAX = 0;
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < n ; ++j) {
            if(boards[i][j] == 0)
                continue;
            for(int k = i ; k > 0 ; --k) {
                
                if(boards[k-1][j] != 0) {
                    //check it's same value and not merged yet
                    if(boards[k-1][j] == boards[k][j] && (!merged[k-1][j] || !merged[k][j])) {
                        //merge
                        boards[k-1][j] *= 2;
                        merged[k-1][j] = true;
                        boards[k][j] = 0;
                        merged[k][j] = false;
                    }
                    break;
                }
                else {
                    merged[k-1][j] = merged[k][j];
                    boards[k-1][j] = boards[k][j];
                    boards[k][j] = 0;
                    merged[k][j] = 0;
                }
            }
            MAX = max(MAX, boards[i][j]);
        }
    }
    /*
    cout<<"UP"<<endl;
    for(int i = 0; i < n ; ++i) {
        for(int j = 0 ; j< n ; ++j) {
            cout << merged[i][j] << " ";
        }
        cout<< endl;
    }
    */
    return MAX;
}

int moveDown(int boards[20][20], bool merged[20][20]) {
    int MAX = 0;
    for(int i = n-1 ; i >=0 ; --i) {
        for(int j = n-1 ; j >= 0; --j) {
            if(boards[i][j] == 0)
                continue;
            for(int k = i ; k < n-1 ; ++k) {
                if(boards[k+1][j] != 0) {
                    //check it's same value and not merged yet
                    if(boards[k+1][j] == boards[k][j] && (!merged[k-1][j] || !merged[k][j])) {
                        //merge
                        boards[k+1][j] *= 2;
                        merged[k+1][j] = true;
                        boards[k][j] = 0;
                        merged[k][j] = false;
                    }
                    break;
                }
                else {
                    boards[k+1][j] = boards[k][j];
                    boards[k][j] = 0;
                    merged[k+1][j] = merged[k][j];
                    merged[k][j] = 0;
                }
            }
            MAX = max(MAX, boards[i][j]);
        }
    }
    /*
    cout<<"DOWN"<<endl;
    for(int i = 0; i < n ; ++i) {
        for(int j = 0 ; j< n ; ++j) {
            cout << merged[i][j] << " ";
        }
        cout<< endl;
    }
    */
    return MAX;
}

int moveLeft(int boards[20][20], bool merged[20][20]) {
    int MAX = 0;
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < n; ++j) {
            if(boards[i][j] == 0)
                continue;
            for(int k = j ; k > 0 ; --k) {
                if(boards[i][k-1] != 0) {
                    //check it's same value and not merged yet
                    if(boards[i][k-1] == boards[i][k] && (!merged[i][k-1] || !merged[i][k])) {
                        //merge
                        boards[i][k-1] *= 2;
                        merged[i][k-1] = true;
                        boards[i][k] = 0;
                        merged[i][k] = false;
                    }
                    break;
                }
                else {
                    boards[i][k-1] = boards[i][k];
                    boards[i][k] = 0;
                    merged[i][k-1] = merged[i][k];
                    merged[i][k] = 0;
                }
            }
            MAX = max(MAX, boards[i][j]);
        }
    }
    /*
    cout<<"LEFT"<<endl;
    for(int i = 0; i < n ; ++i) {
        for(int j = 0 ; j< n ; ++j) {
            cout << merged[i][j] << " ";
        }
        cout<< endl;
    }
    */
    return MAX;
}

int moveRight(int boards[20][20], bool merged[20][20]) {
    int MAX = 0;
    for(int i = n-1 ; i >= 0 ; --i) {
        for(int j = n-1 ; j >= 0 ; --j) {
            if(boards[i][j] == 0)
                continue;
            for(int k = j ; k < n-1 ; ++k) {
                if(boards[i][k+1] != 0) {
                    //check it's same value and not merged yet
                    if(boards[i][k+1] == boards[i][k] && (!merged[i][k+1] || !merged[i][k])) {
                        //merge
                        boards[i][k+1] *= 2;
                        merged[i][k+1] = true;
                        boards[i][k] = 0;
                        merged[i][k] = false;
                    }
                    break;
                }
                else {
                    boards[i][k+1] = boards[i][k];
                    boards[i][k] = 0;
                    merged[i][k+1] = merged[i][k];
                    merged[i][k] = 0;
                }
            }
            MAX = max(MAX, boards[i][j]);
        }
    }
    /*
    cout<<"RIGHT"<<endl;
    for(int i = 0; i < n ; ++i) {
        for(int j = 0 ; j< n ; ++j) {
            cout << merged[i][j] << " ";
        }
        cout<< endl;
    }
    cout<<MAX<<endl;
    */
    return MAX;
}

void dfs(int depth, int direction, int boards[20][20], bool merged[20][20]){
    int num = 0;
    int tempBoards[20][20];
    bool tempMerged[20][20];
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < n ; ++j) {
            tempBoards[i][j] = boards[i][j];
            tempMerged[i][j] = merged[i][j];
        }
    }
    //get result of when move to that way
    // up = 0
    // down = 1
    // left = 2
    // right = 3
    switch (direction)
    {
    case 0:
        num = moveUp(tempBoards, tempMerged);
        break;
    case 1:
        num = moveDown(tempBoards, tempMerged);
    break;
    case 2:
        num = moveLeft(tempBoards, tempMerged);
    break;
    case 3:
        num = moveRight(tempBoards, tempMerged);
    break;
    default:
        break;
    }
    
    if(depth >= 5 ) {
        //cout<<direction<<endl;
        printBoards(tempBoards, tempMerged);
        if(resultMax < num) {
            
            resultMax = num;
        }
        return;
    }
    for(int i =0 ; i < 4; ++i) {
       dfs(depth+1, i, tempBoards, tempMerged);
    }
}

int main() {
    int boards[20][20] = {0};
    bool merged[20][20] = {false};
    cin >> n;
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < n ;++j) {
            cin>>boards[i][j];
        }
    }
    
    for(int i = 0 ; i < 4 ; ++i) {
        dfs(1, i, boards, merged);
    }
    cout << resultMax << endl;
    return 0;
}