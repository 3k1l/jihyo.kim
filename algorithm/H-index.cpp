#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    int idx = 0;
    
    for(int i = 0 ; i <citations.size() ; ++i) {
        idx = citations.size() - i;
        if(idx > citations[i])
            answer = max(answer, citations[i]);
        else
            answer = max(answer, idx);
    }
    
    return answer;
}
//22 27
//1 17 18 19
//1 27
//1 17 18 19 20