#include <iostream>
#include <set>
using namespace std;

#define SUM 0
#define CHECK 1

int numSet[1000001] = {-1};

int getParent(int num1) {
    if(numSet[num1] == num1) {
        return num1;
    }
    else {
        return numSet[num1] = getParent(numSet[num1]);
    }
}

void combineSet(int num1, int num2) {
    num1 = getParent(num1);
    num2 = getParent(num2);
    if(num1 == num2) {
        return;
    }
    else {
        //combine numbers smaller num is parent
        if(num1 < num2) { 
            numSet[num2] = num1;
        }
        else {
            numSet[num1] = num2;
        }
    }
}

string comapreParent(int num1, int num2) {
    return (getParent(num1) == getParent(num2)) ? "YES" : "NO" ;
}

int main() {
    int n, m;
    int command, num1, num2;
    scanf("%d %d", &n, &m);
    //make each n subset from 0 to n
    for(int i = 0 ; i <= n ; ++i) {
        numSet[i] = i;
    }

    for(int i = 0 ; i < m ; ++i) {
        scanf("%d %d %d", &command, &num1, &num2);
        if(command == SUM) {
            combineSet(num1, num2);
        }
        else if(command == CHECK) {
            printf("%s \n", comapreParent(num1, num2).c_str());        
        }
    }
    return 0;
}