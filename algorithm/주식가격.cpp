#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    stack<int> val; // stack for index which doesn't check yet.
    for(int i = 0 ; i < size ; ++i) {
        while((!val.empty()) && (prices[val.top()] > prices[i])) {
            answer[val.top()] = i - val.top();
            val.pop();
        }
        val.push(i);
    }
    while(!val.empty()) {
        answer[val.top()] = size - val.top() -1;
        val.pop();
    }
    return answer;
}