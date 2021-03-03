#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int size = speeds.size();
    int days[size];
    int checked[size];
    for(int i = 0 ; i < size; ++i) {
        float num = (100-progresses[i])/(float)speeds[i];
        days[i] = ceil(num);
        checked[i] = 0;
    }
    int day;
    for(int i = 0 ; i<size ; ++i) {
        if(checked[i] == 0) {
            day = 1;
            for(int j = i+1 ; j < size ; ++j) {
                if(checked[j] == 0 && days[j] <= days[i]) {
                    ++day;
                    checked[j] = 1;
                }
                else
                    break;
            }
            answer.push_back(day);
        }
    }
    return answer;
}