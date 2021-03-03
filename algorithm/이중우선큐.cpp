#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> numbers;
    for(int i = 0 ; i < operations.size() ; ++i) {
        string op = operations[i];
        if(op[0] == 'I') {
            string numString = op.substr(2);
            int num = stoi(numString);
            numbers.push_back(num);
            sort(numbers.begin(), numbers.end(),greater<int>());
        }
        if(op[0] == 'D') {
            if(op[2] == '-') {
                if(!numbers.empty())
                    numbers.pop_back();
            }
            else {
                if(!numbers.empty())
                    numbers.pop_front();
            }
        }
    }
    if(numbers.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(numbers.front());
        answer.push_back(numbers.back());        
    }
    return answer;
}