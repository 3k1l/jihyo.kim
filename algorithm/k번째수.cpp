#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    int start, end, idx;
    for(int i = 0; i < commands.size() ; ++i) {
        temp = array;
        start = commands[i][0]-1;
        end = commands[i][1];
        idx = commands[i][2]-1;
        
        sort(temp.begin()+start, temp.begin()+end);
        answer.push_back(temp[start+idx]);
    }
    return answer;
}