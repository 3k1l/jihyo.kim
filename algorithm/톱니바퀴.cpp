#include <iostream>
#include <string>

using namespace std;

#define POINTLEFT 6
#define POINTRIGHT 2

string cycle[4];

void rotate(int num, int direction) {
    char temp;
    string newCycle ="";
    if(direction == -1) {
        temp = cycle[num][0];
        newCycle.append(cycle[num].substr(1,7));
        newCycle.push_back(temp);
    }
    else if(direction == 1) {
        temp = cycle[num][7];
        newCycle.push_back(temp);
        newCycle.append(cycle[num].substr(0,7));
    }
    cycle[num] = newCycle;
}

void circleRotate(int num, int direction, int wayLeft, int wayRight) {
    char left = cycle[num][POINTLEFT];
    char right = cycle[num][POINTRIGHT];
    int nextDirection;
    if(direction == 1)
        nextDirection = -1;
    else
        nextDirection = 1;
    rotate(num, direction);
    if(wayLeft == 1) {
        if(num > 0 ) {
            if(left != cycle[num-1][POINTRIGHT]) {
                circleRotate(num-1, nextDirection, 1, 0);
            }
        }
    }
    if(wayRight == 1) {
        if(num < 3) {
            if(right != cycle[num+1][POINTLEFT]) {
                circleRotate(num+1, nextDirection, 0, 1);
                
            }
        }
    }
}

int calcScore() {
    int answer = 0;
    if(cycle[0][0] == '1')
        answer += 1;
    if(cycle[1][0] == '1')
        answer += 2;
    if(cycle[2][0] == '1')
        answer += 4;
    if(cycle[3][0] == '1')
        answer += 8;
    return answer;
}

int main() {
    int input, num, direction;

    for(int i = 0 ; i < 4 ; ++i ) {
        getline(cin, cycle[i]);
    }
    scanf("%d", &input);
    for(int i = 0 ; i < input ; ++i) {
        scanf("%d", &num);
        scanf("%d", &direction);
        circleRotate(num-1, direction, 1, 1);
    }
    printf("%d\n", calcScore());
    return 0;
}
