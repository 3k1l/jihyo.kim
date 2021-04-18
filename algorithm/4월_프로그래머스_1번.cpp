#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int result = 0;
    for(int i = 0 ; i < absolutes.size() ; ++i) {
        if(signs[i]) {
            result += absolutes[i];
        }
        else {
            result -= absolutes[i];
        }
    }
    return result;
}