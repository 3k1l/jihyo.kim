#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(int pictureCnt, int studentCnt, int recommands[1000]) {
    int recommandedStudent;
    int recommandCnt[1000] = {0};
    int studentINOUT[1000] = {0};
    vector<pair<int,int> > listUp;
    int minStudent, minIdx;
    int minCnt, minTime;

    for(int i = 0 ; i < studentCnt; ++i) {
        recommandedStudent = recommands[i];
        //cout<<"rec student : "<<recommandedStudent<<'\n';
        recommandCnt[recommandedStudent]++;
        if(studentINOUT[recommandedStudent] == 0) {
            if(listUp.size() == pictureCnt) {
                minCnt = 1000;
                minIdx = 0;
                minTime = 1000;
                for(int j = 0 ; j < listUp.size() ; ++j) {
                    int student = listUp[j].first;
                    int time = listUp[j].second;
                    if(recommandCnt[student] < minCnt) {
                        minCnt = recommandCnt[student];
                        minStudent = student;
                        minIdx = j;
                        minTime = time;
                    }
                    else if (recommandCnt[student] == minCnt) {
                        if(time < minTime) {
                            minCnt = recommandCnt[student];
                            minStudent = student;
                            minIdx = j;
                            minTime = time;
                        }
                    }

                }
                listUp[minIdx] = make_pair(recommandedStudent,i);
                recommandCnt[minStudent] = 0;
                studentINOUT[minStudent] = 0;                
            }
            else {
                listUp.push_back(make_pair(recommandedStudent, i));
            }
            studentINOUT[recommandedStudent] = 1;
        }//end of studentINOUT
    }
    sort(listUp.begin(), listUp.end());
    for(int i = 0 ; i < listUp.size() ; ++i)
        cout<<listUp[i].first<<' ';
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