// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int min = 1;
    sort(A.begin(), A.end());
    for(int i = 0 ; i < (int) A.size() ; ++i){
        if(min == A[i])
            ++min;
        else if (min < A[i]){
            break;
        }
    }
    return min;
}