#include<iostream>
using namespace std;

int main() {
    int tcNum, height, width, customer;
    //YYXX YXX is room number
    int x, y, roomNumber;
    scanf("%d", &tcNum);
    for(int i = 0 ; i < tcNum ; ++i) {
        scanf("%d %d %d", &height, &width, &customer);
        //find floor by height
        y = customer % height;
        //find x
        x = customer / height + 1;
        //if same as height
        if(y == 0) {
            y = height;
            x--;
        }
        //room number is YYXX or YXX
        roomNumber = y*100 + x;
        //print out result
        printf("%d \n", roomNumber);
    }
    return 0;
}