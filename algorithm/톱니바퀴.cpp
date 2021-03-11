#include <iostream>


using namespace std;

static const POINTLEFT = 0;
static const POINTRIGHT = 4;

void rotate(string cycle, int direction) {
    int temp;
    if(direction == -1) {
        temp = cycle[0];
    }
    else if(direction == 1) {

    }
}

void solution(string cycle[4], int num, int direction) {
    rotate(cycle[num],direction);
    if(num >)
}

int calcScore(string cycle[4]) {
    int answer = 0;
    if(cycle[0][2] == '1')
        answer += 1;
    if(cycle[1][2] == '1')
        answer += 2;
    if(cycle[2][2] == '1')
        answer += 4;
    if(cycle[3][2] == '1')
        answer += 8;
    return answer;
}

int main() {
    string cycle[4];
    int input, num, direction;

    for(int i = 0 ; i < 4 ; ++i ) {
        getline(cin, cycle[i]);
    }
    scanf("%d", &input);
    for(int i = 0 ; i < num ; ++i) {
        scanf("%d", &num);
        scanf("%d", &direction);
        solution(cycle, num-1, direction);
    }

    printf("%d \n", calcScore(cycle));
    
        
    return 0;
}
