#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void solution(int pictureCnt, int studentCnt, int recommands[1000]) {
    int recommandedStudent;
    int recommandCnt[1000] = {0};
    int studentINOUT[1000] = {0};
    int listUp[pictureCnt];
    int minStudent = recommands[0];
    int cnt = 0;

    for(int i = 0 ; i < studentCnt; ++i) {
        recommandedStudent = recommands[i];
        if(studentINOUT[recommandedStudent] == 0) {
            if(cnt == pictureCnt) {
                int* p = find(listUp, listUp+pictureCnt, minStudent);
                p = recommandedStudent;
            }
            else {
                listUp[cnt] = recommandedStudent;
            }
        }
        else {
            ++cnt;  
        }      
        ++recommandCnt[recommandedStudent];
        if(recommandCnt[minStudent] > recommandCnt[recommandedStudent]) {
            minStudent = recommandedStudent;
        }
    }
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