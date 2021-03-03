#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; // equal time
    queue<pair<int,int>> bridgeOn;
    queue<int> pending;
    int bridgeWeight = 0;
    int idx = 0;
    
    for(int truck  : truck_weights)
        pending.push(truck);
    
    while(true) {
        ++answer;
        if(pending.empty() && bridgeOn.empty()) {
            answer--;
            break;
        }
        if(!bridgeOn.empty()) {
            if(answer - bridgeOn.front().first >= bridge_length) {
                //cout <<"OUT time : "<<answer <<" truck : "<<bridgeOn.front().second<<endl;
                bridgeWeight -= bridgeOn.front().second;
                bridgeOn.pop();
            } 
        }
        if(!pending.empty()) {
            if(answer > idx && bridgeWeight + pending.front() <= weight) {
                //cout <<"IN time : "<< answer <<" truck : "<<pending.front()<<endl;
                bridgeOn.push(make_pair(answer, pending.front()));
                bridgeWeight += pending.front() ;
                pending.pop();
                ++idx;
            }
        }
    }
    return answer;
}