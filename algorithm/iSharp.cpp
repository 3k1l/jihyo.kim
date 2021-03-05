#include <iostream>

using namespace std;

void solution(string input) {
    bool endOp = false;
    string opBase = "";
    string val = "";
    string opEach = "";
    
    for(int i = 0 ; i < input.length(); ++i) {
        if(!endOp) {
            if(input[i] == ' ') {
                endOp = true;
            }
            else 
                opBase.push_back(input[i]);
        }
        else {
            if(isalpha(input[i])) {
                val.push_back(input[i]);
                //cout<<input[i]<<'\n';
            }
            else if(input[i] == ',' || input[i] == ';') {
                cout << opBase;
                while(!opEach.empty()) {
                    char c = opEach.back();
                    if(c == ']') {
                        opEach.pop_back();
                    }
                    else if(c == '['){
                        cout<<c<<']';
                        opEach.pop_back();
                    }
                    else {
                        cout<<c;
                        opEach.pop_back();
                    }
                }
                cout<<' '<< val << ";\n" ;
                val = "";
                opEach = "";
            }
            else if(input[i] != ' '){
                opEach.push_back(input[i]);
            }
        }
        
    }
}

int main() {
    string input;
    getline(cin,input);
    solution(input);
    return 0;
}