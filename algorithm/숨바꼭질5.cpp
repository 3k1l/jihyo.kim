#include <iostream>

using namespace std;
int answer = 500001;

void go(int location_sister,int location_subin, int second) {
    location_subin += second;
    cout<<location_sister<<" "<<location_subin<<" "<<second<<"\n";
    if(location_subin == location_sister) {
        answer = min(answer, second);
        return;
    }
    if(location_subin > 500000) {
        return;
    }
    if(second > answer)
        return;
    if(second> 10)
        return;

    // go -1
    if(location_sister >= 1 ) {
        //cout<<"1"<<endl;
        go(location_sister-1, location_subin, second+1);
    }
    // go +1
    if(location_sister < 500000 )
        go(location_sister+1, location_subin, second+1);
    // go double
    if(location_sister < 250000 )
        go(location_sister*2, location_subin, second+1);
}

int main() {
    int location_subin, location_sister;
    int second = 0;
    scanf("%d %d", &location_sister, &location_subin);
    //go to find answer
    go(location_sister, location_subin, second);
    printf("%d \n", answer);
    return 0;
}