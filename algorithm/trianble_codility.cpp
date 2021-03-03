// you can use includes, for example:
#include <algorithm>
#include <iostream>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int res = 0;
    sort(A.begin(),A.end());

    if (A.size() < 3 || A.empty())
        return 0;

    for (int i = A.size()-1; i >= 2 ; --i) {
        if (long(A[i-2]) + long(A[i-1]) > A[i]) {
            res = 1;
            break;
            
        }
    }
    return res;
}