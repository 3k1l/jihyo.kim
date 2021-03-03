// you can use includes, for example:
// #include <algorithm>
#include <stack>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) {

    // write your code in C++14 (g++ 6.2.0)
    int result = 1;
    stack<int> hStack;
    hStack.push(H[0]);
    int i = 1;

    while(i < H.size()) {

        if(H[i] < hStack.top()) {
            hStack.pop();
            if(!hStack.empty())
                continue;
            hStack.push(H[i]);
            ++result;
        }
        else if(H[i] > hStack.top()) {
            hStack.push(H[i]);
            ++result;
        }
        ++i;
    }
    return result;
}
