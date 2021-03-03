#include <string>
#include <vector>
#include <unordered_map>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first < b.first)
        return false;
    else if(a.first == b.first) {
        if(a.second < b.second)
            return true;
        else
            return false;
    }
    else
        return true;
}

bool compareMax(pair<string, int> a, pair<string, int> b) {
    if(a.second > b.second)
        return true;
    else
        return false;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<int, int>>sortedPlays;
    unordered_map<string ,vector<int>> catagory;
    unordered_map<string ,int> catagoryMax;
    vector<pair<string,int>> sortMax;
    int maxPlay = -1;
    
    for(int i = 0; i < plays.size() ; ++i) {
        sortedPlays.push_back(make_pair(plays[i], i));
    }
    sort(sortedPlays.begin(), sortedPlays.end(), compare);
    
    for(int i = 0 ; i < sortedPlays.size() ; ++i) {
        int idx = sortedPlays[i].second;
        int playCount = sortedPlays[i].first;
        catagory[genres[idx]].push_back(idx);
        catagoryMax[genres[idx]] += playCount;
    }
    
    for(pair<string, int> item : catagoryMax) {
        sortMax.push_back(item);
    }
    sort(sortMax.begin(), sortMax.end(), compareMax);
    
    for(pair<string, int> it : sortMax) {
        catagory[it.first];
        for(int i = 0 ; i < 2 && i < catagory[it.first].size() ; ++i) {
            answer.push_back(catagory[it.first][i]);
           // cout << catagory[it.first][i] <<" ";
        }
        //cout<<endl;
    }
    return answer;
}