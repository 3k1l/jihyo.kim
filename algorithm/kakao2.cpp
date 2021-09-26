#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    string changed = "";
    string value = "";
    int i = 0;
    while(n >= k) {
        int val = n % k;
        changed +=  to_string(val);
        n /= k;
        ++i;
    }
    changed +=  to_string(n);
    //reverse
    if(changed.length() >0) {
        for(int i = changed.length() ; i >= 0; --i) {
            if(changed[i] >= '0' && changed[i] <= '9')
               value += changed[i];
        }
    }
    bool WORD = true;
    string P ="";
    vector<string> pVector;
    for(int i = 0 ; i < value.length() ; ++i) {
        if(value[i] >= '1' && value[i]<= '9') {
            if(!WORD) {
                WORD = true;
            }
            P += value[i];
        }
        else {
            if(WORD) {
                pVector.push_back(P);
                P = "";
            }
            WORD = false;
        }
    }
    if(WORD) {
        pVector.push_back(P);
    }
    //check prime or not
    for(string item : pVector) {
        bool prime = true;
        int num = stoi(item);
        if(num == 1) {
            continue;
        }
        else {
            for(int i = 2; i < num ; ++i) {
                if(num % i == 0) {
                    prime = false;
                    break;
                }
            }
            if(prime) {
                ++answer;
            }
        }  
    }
    return answer;
}