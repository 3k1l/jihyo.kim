#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
#define MAX_LEN 7
bool checked[MAX_LEN] = {false,};
vector<int> resultNum;

void permutation(int* num, int val, int n, int r, int depth) {
    if(depth == r) {
        if(val != 1 && val != 0 && resultNum.end() == find(resultNum.begin(), resultNum.end(), val)){
            resultNum.push_back(val);
        }
        return;
    }
    for(int i = 0 ; i < n ; ++i) {
        if(!checked[i]) {
            checked[i] = true;
            val += num[i]*pow(10, depth);
            permutation(num, val, n, r, depth+1);
            val -= num[i]*pow(10, depth);
            checked[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    int len = numbers.size();
    int val = 0;
    int nums[len];
    
    for(int i = 0 ; i < len ; ++i) 
        nums[i] = numbers[i]-'0';
    
    for(int i = 1 ; i <= len ; ++i) {
        permutation(nums, val, len, i, 0);
    }
    
    for(int num : resultNum) {
        bool decimal = true;
        for(int i = 2 ; i <num ;++i) {
            if((num % i) == 0) {
                decimal = false;
                break;
            }
        }
        if(decimal)
            answer++;
    }
    
    return answer;
}