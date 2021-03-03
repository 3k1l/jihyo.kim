#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    int map[500][500] = {0};
    map[0][0] = triangle[0][0];
    for(int i = 1 ; i < size; ++i) {
        for(int j = 0 ; j < triangle[i].size(); ++j) {
            if(j == 0)
                map[i][j] = map[i-1][j] + triangle[i][j];
            else if(j == triangle[i].size()-1)
                map[i][j] = map[i-1][j-1] + triangle[i][j];
            else
                map[i][j] = max(map[i-1][j-1], map[i-1][j]) + triangle[i][j];
        }
    }
    for(int i = 0 ; i < triangle[size-1].size(); ++i) {
        answer = max(answer,map[size-1][i] );
    }
    return answer;
}