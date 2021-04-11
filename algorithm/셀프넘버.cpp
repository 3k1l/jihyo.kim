#include <iostream>
#include <vector>
#define MAX_NUM 10001
using namespace std;

int solution(int num) {
    int val = num;
    while(true) {
        if(num == 0)
            break;
        val = val + (num % 10);
        num /= 10;
    }
    return val;
}

int main() {
    int num = 1;
    int val;
    bool self_number[MAX_NUM] = {false};

    while(num < MAX_NUM) {
        val = solution(num);  
        if(val <= MAX_NUM) {
            self_number[val] = true;
        }
        ++num;
    }

    for(int i = 1 ; i < MAX_NUM ; ++i) {
       if(!self_number[i]) 
            printf("%d\n",i);      
    }
    return 0;
}