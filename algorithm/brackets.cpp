// you can use includes, for example:
// #include <algorithm>
#include <stack>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int result = 0;
    stack <char> stack_cnt;
    
    if (((int) S.size()% 2) == 1)
        return 0;
    if(S.size() == 0)
        return 1;
        
    for (int i = 0 ; i < (int)S.size() ; ++i) {
        if(S[i] == '[' || S[i] == '{' || S[i] == '(') {
           stack_cnt.push(S[i]);
        }
        else {
            char fair = stack_cnt.top();
            stack_cnt.pop();
            if (S[i] == ')') {
                if (fair == '(')
                    result = 1;
                else {
                    result = 0;
                    break;
                }
           }
            else if (S[i] == ']') {
                if (fair == '[')
                    result = 1;
                else {
                    result = 0;
                    break;
                }
           }            
           else if (S[i] == '}') {
                if (fair == '{')
                    result = 1;
                else {
                    result = 0;
                    break;
                }
           }
       }
    }
    if (!stack_cnt.empty())
        result = 0;
    return result;
}