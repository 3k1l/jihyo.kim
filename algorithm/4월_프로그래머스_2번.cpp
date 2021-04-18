#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.length();
    string tempString = s;
    string front, back;
    stack<char> stackS;
    char tempC;
    bool check = true;
    for(int i = 0 ; i < len ; ++i) {
        check = true;
        front = s.substr(0,i);
        back = s.substr(i);
        tempString = back + front;
        for(int j = 0 ; j < tempString.length() ; ++j) {
            if(tempString[j] == '{') {
                stackS.push(tempString[j]);
            }
            else if(tempString[j] == '[') {
                stackS.push(tempString[j]);
            }
            else if(tempString[j] == '(') {
                stackS.push(tempString[j]);
            }
            else if(tempString[j] == ')') {
                if(stackS.empty()) {
                    check = false;
                    break;
                }
                else {
                    tempC = stackS.top();
                    stackS.pop();
                    if(tempC != '(') {
                    check = false;
                    break;
                    }
                }
            }
            else if(tempString[j] == '}') {
                if(stackS.empty()) {
                    check = false;
                    break;
                }
                else {
                    tempC = stackS.top();
                    stackS.pop();
                    if(tempC != '{') {
                    check = false;
                    break;
                    }
                }
            }
            else if(tempString[j] == ']') {
                if(stackS.empty()) {
                    check = false;
                    break;
                }
                else {
                    tempC = stackS.top();
                    stackS.pop();
                    if(tempC != '[') {
                    check = false;
                    break;
                    }
                }
            }
        }
        if(!stackS.empty()) {
            check = false;
            while(!stackS.empty())
                stackS.pop();
        }
        if(check) {
            ++answer;
        }
    }
    return answer;
}