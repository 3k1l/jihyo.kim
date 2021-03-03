// you can use includes, for example:
#include <stack>
#include <algorithm>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int cnt = 0;
    stack<int> down_A;
    stack<int> down_B;
    int fish_A;
    int state_B;
    int size = A.size();
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    for (int i = 0 ; i < size; ++i ){
        fish_A = A.back();
        A.pop_back();
        state_B = B.back();
        B.pop_back();

        if (state_B) {
            down_A.push(fish_A);
            down_B.push(state_B);
        }
        else {
            while (!down_A.empty() && down_A.top() < fish_A) {
                down_A.pop();
            }
            if (down_A.empty()) {
                ++cnt;
            }
        }
    }
    cnt += down_A.size();

    return cnt;
}