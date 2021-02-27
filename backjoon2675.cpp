#include <iostream>
#include <string>

using namespace std;
void solution(int repeat, string phase) {
    string result;
    for(int i = 0 ; i < phase.size(); ++i) {
        for(int j = 0 ; j < repeat; ++j) {
            result.append(phase.substr(i,1));
        }
    }
    cout<<result<<'\n';
}

int main(void) {
    int cnt, repeat;
    scanf("%d",&cnt);
    string phase;
    for(int i = 0 ; i< cnt; ++i) {
        cin>>repeat;
        cin>>phase;
        solution(repeat, phase);
    }
}