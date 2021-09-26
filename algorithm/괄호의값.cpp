#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;

int solution(string input) {
    stack<char> inputS;
    int result = 0;
    int num = 1;
    for(int i = 0 ; i < input.length() ; ++i) {
        switch(input[i]) {
            case '(' :
                num *= 2;
                inputS.push(input[i]);
                break;
            case '[' :
                num *= 3;
                inputS.push(input[i]);
                break;
            case ')' :
                if(inputS.empty() || inputS.top() != '(') {
                    return 0;
                }
                else {
                    if(input[i-1] == '(' )
                        result += num;
                    inputS.pop();
                    num /= 2;
                }
                break;
            case ']' :
                if(inputS.empty() || inputS.top() != '[') {
                    return 0;
                }
                else {
                    if(input[i-1] == '[' )
                        result += num;
                    inputS.pop();
                    num /= 3;
                }
                break;
            break;
        }
    }
   
    return result;
}
//(2 9
int main() {
    string input;
    getline(cin, input);
    cout<<solution(input)<<'\n';
    return 0;
}