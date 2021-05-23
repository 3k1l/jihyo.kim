#include <iostream>

using namespace std;

struct Ball {
    int y;
    int x;
};

Ball hole;
char boards[11][11];
int n, m, answer;

enum direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
};


void goDirection(Ball &red, Ball &blue, int direction) {
    switch(direction) {
        case LEFT :
            //go red
            
            //go blue
            break;
        case RIGHT :

            break;
        case UP :

            break;
        case DOWN :

            break;
    }
}
void bfs(Ball red, Ball blue, int depth) {
    Ball tempRed, tempBlue;
    if(red.y == hole.y && red.x == hole.x) {
        if(blue.y == hole.y && blue.x == hole.x) {
            return ;
        }
        else {
            answer = depth;
            return;
        }
    }
    if(depth == 10) {
        return;
    }    
    //go directon
    for(int i = 0 ; i < 4 ; ++i) {
        //go direction
        tempRed = red;
        tempBlue = blue;
        goDirection(tempRed, tempBlue, i);
        bfs(tempRed, tempBlue, depth+1);
    }
    
}

int main() {
    Ball redBall, blueBall;
    answer = -1;
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < m ; ++j) {
            cin >> boards[i][j];
            if(boards[i][j] == 'R') {
                redBall.y = i;
                redBall.x = j;
            }
            if(boards[i][j] == 'B') {
                blueBall.y = i;
                blueBall.x = j;
            }
            if(boards[i][j] == '0') {
                hole.y = i;
                hole.x = j;
            }
        }
    }
    //
    bfs(redBall, blueBall, 0);
    cout << answer;
    return 0;
}