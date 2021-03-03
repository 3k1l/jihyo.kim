// you can use includes, for example:
// #include <algorithm>
#include<vector>
//#include<iostream>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    vector<char> data;
    int result = 1;

    for (int i = 0; i < (int)S.size(); ++i) {
        if (S[i] == '(') {
            data.push_back(S[i]);
        }
        else {
            if(data.empty()){
                result = 0;
                break;
            }
            else {
                data.pop_back();
            }
        }
    }
    if(!data.empty())
        result = 0;
        
    return result;

}