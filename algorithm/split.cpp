#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<string> split(string input, char a) {
    stringstream ss(input);
    string temp;
    vector<string> answer;
    while(getline(ss, temp, a)) {
        answer.push_back(temp);
    }
    return answer;
}   

int main() {
    string input;
    getline(cin, input);
    vector<string> answers = split(input, ' ');
    for(string temp : answers)
        cout<<temp<<endl;
}