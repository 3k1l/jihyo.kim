#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int curWeight, last;
    bool check[50000] = {false};
    sort(people.begin(), people.end(), greater<int>());
    last = people.size()-1;
    for(int i = 0 ; i < people.size(); ++i) {
        curWeight = people[i];
        if(!check[i]) {
            check[i] = true;
            for(int j = last ; j > i ; --j) {
                if(check[j])
                    continue;
                if(people[j] > (limit - curWeight))
                    break;
                else { 
                    last--;
                    check[j] = true;
                    break;   
                }
            }
            ++answer;
        }
    }
    return answer;
}