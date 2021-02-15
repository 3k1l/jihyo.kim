#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int curWeight;
    bool check[50000] = {false};
    sort(people.begin(), people.end(), greater<int>());
    for(int i = 0 ; i < people.size(); ++i) {
        curWeight = people[i];
        if(!check[i]) {
            check[i] = true;
            for(int j = i+1 ; j < people.size(); ++j) {
                if(people[j] <= limit - curWeight && !check[j]) {
                    check[j] = true;
                    break;
                }
            }
            ++answer;
        }
    }
    return answer;
}