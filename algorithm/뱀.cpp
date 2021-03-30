#include <iostream>
using namespace std;

int main() {
    int boardSize, appleNum, directionNum;
    int applesRow[100];
    int applesCol[100];
    int seconds[100];
    char directions[100];
    //intialize
    cin >> boardSize >> appleNum;
    for(int i = 0 ; i < appleNum ; ++ i) {
        cin >> applesRow[i];
        cin >> applesCol[i];
    }
    cin >> directionNum;
    for(int i = 0 ; i < directionNum ; ++ i) {
        cin >> seconds[i];
        cin >> directions[i];
    }
    //solution
    
    return 1;
}