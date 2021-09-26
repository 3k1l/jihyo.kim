#include <iostream>

using namespace std;
long long n, b, c;
long long num[1000000];

long long  solution(int n) {
    long long cnt,num;
    //step 1 for b
    cnt = 1;
    n -= b;
    //step 2 for c
    if(n > 0){
        num = (n + (c-1)) / (c);
        cnt += num;
    } 
    return cnt;
}

int main(){
    long long n;
    long long result;
    result = 0 ;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) {
        cin  >> num[i];
    }
    cin >> b >> c;
    for(int i = 0 ; i < n ; ++i) {
        result += solution(num[i]);
    }
    printf("%lld", result);

    return 0;
}