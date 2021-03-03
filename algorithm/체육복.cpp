#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    int clothes[31] = {1};
    bool lostCheck[31] = {false};
    int num = 0;
    for(int i = 0  ; i < lost.size() ; ++i) {
        num = lost[i];
        clothes[num] = 0;
        lostCheck[num] = true;
    }
    for(int i = 0  ; i < reserve.size() ; ++i) {
        num = reserve[i];
        clothes[num] = 2;
        if(lostCheck[num]) {
            lostCheck[num] = false;
            clothes[num] = 1;
        }
    }
    for(int i = 0 ; i <lost.size() ; ++i) {
        num = lost[i];
        if(lostCheck[num]) {
            if(clothes[num-1] >= 2 ) {
                lostCheck[num] = false;
                clothes[num-1] =1;
            }
            else if(clothes[num+1] >= 2 ) {
                lostCheck[num] = false;
                clothes[num+1] =1;
            }
        }
    }
    for(int i = 0 ; i< 30 ; ++i) {
        if(lostCheck[i])
            answer -=1;
    }
    return answer;
}