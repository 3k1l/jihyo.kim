#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

int findMost(map<int, int> cntNum) {
    int answer, cntMax;
    cntMax = 1;
    vector<int> cntMost;

    for(auto iter : cntNum) {
        if(cntMax < iter.second) {
            cntMax = iter.second;
            answer = iter.first;                
            cntMost.clear();
        }
        if(cntMax == iter.second) {
            answer = iter.first;                
            cntMost.push_back(iter.first);
        }
    }

    if(cntMost.size() > 1) {
        sort(cntMost.begin(), cntMost.end());
        answer = cntMost[1];
    }

    return answer;
}

int main() {
    int n, val;
    scanf("%d", &n);
    vector<int> num;
    double sum = 0;
    map<int,int> cntNum;

    for(int i = 0 ; i < n ; ++i) {
        scanf("%d", &val);
        num.push_back(val);
        sum +=val;
        if(cntNum.find(val) == cntNum.end()) {
            cntNum[val] = 1;
        }
        else {
            cntNum[val]++;
        }
    }
    sort(num.begin(), num.end());
    //1
    float avg = round(sum/n);
    cout<<avg<<'\n';
    //2
    cout<<num[n/2]<<'\n';
    //3
    cout<<findMost(cntNum)<<'\n';
    //4
    cout<<(num[n-1] - num[0])<<'\n';   
    return 0;
}