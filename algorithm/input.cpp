#include <iostream>

using namespace std;

int main() {
    int n;
    int arr[10];
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
        cin >> arr[i];
        
    for(int i = 0 ; i < n ; ++i)
        cout <<"test : "<< arr[i] << endl;
}