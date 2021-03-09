#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void solution(int pictureCnt, int studentCnt, int recommands[1000]) {
    map<int, pair<int,int> > pictures;
    for(int i = 0 ; i < studentCnt; ++i) {
        if(pictures.end() == pictures.find(recommands[i])) {
            if(pictures.size() == pictureCnt) {
                pair<int, int> minRecord;
                int idx = pictures.begin()->first;
                minRecord= pictures.begin()->second;
                for(auto item : pictures) {
                    if(item.second < minRecord) {
                        idx = item.first;
                        minRecord = item.second;
                    }
                }
                pictures.erase(idx);
                pictures[recommands[i]].first = 1;
                pictures[recommands[i]].second = i;               
            }
            else {
                pictures[recommands[i]].first = 1;
                pictures[recommands[i]].second = i;
            }
        }
        else
            ++pictures[recommands[i]].first;
    }
    for(auto item : pictures)
        cout<<item.first<<' ';
}

int main() {
    int pictureCnt, studentCnt;
    int recommands[1000];
    scanf("%d", &pictureCnt);
    scanf("%d", &studentCnt);
    for(int i = 0 ; i < studentCnt ; ++i)
        scanf("%d", &recommands[i]);
    solution(pictureCnt, studentCnt, recommands);

    return 0;
}