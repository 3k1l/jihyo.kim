#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> id_map;
    map<string, int> callingIdMap;
    int idData[1001][1001] = {0};
    int answerValue[1001] = {0};
    //set map for id
    int index = 0;
    for(string id : id_list) {
        id_map.insert(make_pair(id, index++));
    }

    for(string data : report) {
        //find reporter and reportee
        string reporter = "";
        string reportee = "";
        bool findSpace = false;
        for(int i = 0 ; i < data.length() ; ++i) {
            if(data[i] == ' ') {
                findSpace = true;
                continue;
            }
            if(findSpace) {
                reportee += data[i];
            }
            else {
                reporter += data[i];
            }
        }
        //find id_index
        map<string, int> :: iterator reporterIt = id_map.find(reporter);
        map<string, int> :: iterator reporteeIt = id_map.find(reportee);
        if(idData[reporterIt->second][reporteeIt->second] == 0) {
            idData[reporterIt->second][reporteeIt->second] = 1;
            //add 
            map<string, int> :: iterator it = callingIdMap.find(reportee);
            if(it == callingIdMap.end()) {
                callingIdMap.insert(make_pair(reportee, 1));
            }
            else {
                ++it->second;
            }
        }
    }
    for(auto it : callingIdMap) {
        if(it.second >= k) {
            map<string, int> :: iterator banIt = id_map.find(it.first);
            for(int i = 0 ; i < id_list.size(); ++i) {
                if(idData[i][banIt->second] == 1) {
                    answerValue[i]++;
                }
            }
        }
    }
    for(int i = 0 ; i < id_list.size(); ++i) {
        answer.push_back(answerValue[i]);
    }
    return answer;
}