#include <iostream>
#include <stack>
using namespace std;

void solution(string input) {
    stack<char> inputS;
    stack<int> valueS;
    int result = 0;
    int val = 1;
    char curChar;
    bool INOUT = false;

    for(int i = 0 ; i < input.length() ; ++i) {

        if(inputS.empty()) {
            //
        }
        else {
            curChar = inputS.top();
        }
        
        if(input[i] == '(' || input[i] == '[') {
            inputS.push(input[i]);
            if(curChar == '(' || curChar=='[') {
                //INOUT = true;
            }

        }
        else {
            if(curChar == '(') {
                if(input[i] == ')') {
                    inputS.pop();
                    val *= 2;
                    if(INOUT) {
                        valueS.push(val);
                        val = 1;
                    }
                    else {

                    }
                }
                else if(input[i] == ']') {
                    result = 0;
                    break;
                }
            }
            else if (curChar == '[') {
                if(input[i] == ']') {
                    inputS.pop();
                    val *= 3;
                    if(INOUT) {
                        valueS.push(val);
                        val = 1;
                    }
                    else {

                    }
                }
                else if(input[i] == ')') {
                    result = 0;
                    break;
                }

            }
        }
    }
    cout<<result<<'\n';
}

int main() {
    string input;
    getline(cin, input);
    solution(input);
    return 0;
}