#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> person1 = {1, 2, 3, 4, 5};
    vector<int> person2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> person3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int count[3] = {0,};
    for(int i = 0 ; i < answers.size() ; ++i) {
        if(answers[i]  == person1[i%5])
            ++count[0];
        if(answers[i]  == person2[i%8])
            ++count[1];
        if(answers[i]  == person3[i%10])
            ++count[2];
    }
    
    int maxNum = 0;
    for(int i = 0 ; i < 3 ; ++i ) {
        maxNum = max(maxNum , count[i]);
    }
    
    for(int i = 0 ; i < 3 ; ++i ) {
        if(maxNum == count[i])
            answer.push_back(i+1);
    }
    return answer;
}