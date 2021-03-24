#include <iostream>
using namespace std;

bool printArray(int array[5]) {
    bool done = true;
    for(int i = 0 ; i < 5 ; ++i) {
        printf("%d ",array[i]);
        if(array[i] != i+1) {
            done = false;
        }
    }
    printf("\n");
    return done;
}

void solution(int array[5]) {
    bool done = false;
    int index = 0;
    while(!done) {
        index = index % 4;
        if(array[index] > array[index+1]) {
            swap(array[index], array[index+1]);
            done = printArray(array);  
        }
        ++index;
    }
}

int main() {
    int array[5];

    for(int i = 0 ; i < 5; ++i)
        scanf("%d", &array[i]);

    solution(array);
}