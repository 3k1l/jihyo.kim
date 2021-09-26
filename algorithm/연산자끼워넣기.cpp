#include <iostream>

using namespace std;

int maxResult = -1000000000;
int minResult =  1000000000; 

void dfs(int arr[10], int op[4], int cur_op, int cur_index, int n, int result) {
    int temp[4] = {0};
    for(int i = 0 ; i < 4 ; ++i) {
        temp[i] = op[i];
    }
    switch (cur_op)
    {
    case 0 :
        result += arr[cur_index+1];
        temp[cur_op]--;
        break;
    case 1 :
        result -= arr[cur_index+1];
        temp[cur_op]--;
        break;
    case 2 :
        result *= arr[cur_index+1];
        temp[cur_op]--; 
        break;
    case 3 :
        result /= arr[cur_index+1];
        temp[cur_op]--;
        break;
    default:
        break;
    }
    //end point
    if(cur_index == n-2) {
        minResult = min(minResult , result);
        maxResult = max(maxResult , result);
    }
    for(int i = 0 ; i < 4 ; ++i) {
        if(temp[i] != 0) {
            dfs(arr, temp, i, cur_index+1, n, result);
        }
    }
}

int main() {
    int n;
    cin >> n;
    int num[10];
    int op[4] = {0};
    for(int i = 0 ; i < n ; ++i) {
        cin >> num[i];
    }
    for(int i = 0 ; i < 4 ; ++i) {
        cin >> op[i];
    }
    for(int i = 0 ; i < 4; ++i) {
        if(op[i] != 0) {
            dfs(num, op, i, 0, n, num[0]);
        }
    }
    cout << maxResult << endl;
    cout << minResult << endl;
    return 0;
}