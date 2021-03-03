#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int> > waitQ;
    priority_queue<int> pq;
    pair<int, int> topNode;
    int count;
    for(int i = 0 ; i < priorities.size(); ++i) {
        waitQ.push(make_pair(priorities[i], i));
        pq.push(priorities[i]);
    }
    while(!waitQ.empty()) {
        topNode = waitQ.front();
        waitQ.pop();
        if(topNode.first == pq.top()) {
            pq.pop();
            ++count;
            if(topNode.second == location) {
                answer = count;
                break;
            }
        }
        else {
            waitQ.push(topNode);
        }
    }
    return answer;
}