#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solution(string input) {
    string output;
    string word;
    bool INOUT = false;
    for(int i = 0 ; i <input.length();++i) {
        char c = input[i];
        if(c == '<') {
            reverse(word.begin(), word.end()); 
            output.append(word);
            word="";
            INOUT = true;
            output.push_back(c);
            continue;
        }
        else if(c == '>') {
            INOUT = false;
            output.push_back(c);
            continue;
        }
        if(INOUT) {
            output.push_back(c);
        }
        else {
            if(i == input.length()-1) {
                word.push_back(c);
                reverse(word.begin(), word.end()); 
                output.append(word);
                break;
            }
            if(c == ' ') {
                reverse(word.begin(), word.end()); 
                output.append(word);
                output.push_back(' ');
                word="";
            }
            else {
                word.push_back(c);
            }
        }
    }
    
    cout<<output<<'\n';
}
int main() {
    string input;
    getline(cin, input);
    solution(input);
    return 0;
}