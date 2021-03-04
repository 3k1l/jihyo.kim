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
                int len = opEach.length();
                for(int i = 0 ; i < len; ++i) {
                    char c = opEach.back();
                    cout<<c;
                    opEach.pop_back();
                }
                cout<<' '<< val << ";\n" ;
                val = "";
                opEach = "";
            }
            else if(input[i] != ' '){
                cout<<input[i]<<'\n';
                opEach.push_back(input[i]);
            }
        }
        
    }
}

int main() {
    string input;
    getline(cin,input);
    solution(input);
    return 1;
}