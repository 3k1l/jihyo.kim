#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, answer;
    answer =0;
    pair<int, int> square;
    pair<int, int> boards[1001];
    cin >> n;
    for(int i = 0 ; i < n ; ++i) {
        int a,b;
        cin >> a >> b;
        boards[i] = make_pair(a, b);
    }
    sort(boards, boards+n);
    int index = 0;
    while(index < n-1) { // need to check
        int result = 0;
        int start = boards[index].first;
        int curHeight = boards[index].second;
        int secondHeight = 0;
        int secondEnd = 0;
        bool CURISMAX = false;
        for(int i = index+1 ; i < n; ++i) {
            if(boards[i].second >= curHeight) { // need to check when it's same
                result = (boards[i].first - start) * curHeight;
                answer += result;
                index = i;
                CURISMAX = true;
                break;
            }
            else {
                if(boards[i].second > secondHeight) {
                    secondEnd = boards[i].first;
                    secondHeight = boards[i].second;
                    index = i;  
                }
            }
        } // end of for
        if(!CURISMAX) { // means find sth
            result = curHeight;
            result += (secondEnd - 1 - start) * secondHeight ;
            answer += result;
        }
    }
    //for last
    answer += boards[n-1].second;
    cout << answer << endl;
    return 0;
}