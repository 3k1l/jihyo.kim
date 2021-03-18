#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

struct cmp {
    bool operator()(int num1, int num2) {
        if(abs(num1) != abs(num2))
            return abs(num1) > abs(num2);
        else {
            return num1 > num2;
        }

    }
};

int main() {
    int n, num;
    priority_queue<int, vector<int>, cmp> pq;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i) {
        scanf("%d", &num);
        if(num != 0)
            pq.push(num);
        else {
            if(!pq.empty()) {
                cout<<pq.top()<<'\n';
                pq.pop();
            }
            else
                cout<<"0"<<'\n';

        }
    }
    return 0;
}