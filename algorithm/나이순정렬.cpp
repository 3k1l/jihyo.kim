#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int, string> num1, pair<int, string> num2) {
    return num1.first < num2.first ;
}

int main() {
    int n;
    pair<int, string> tmp;
    vector<pair<int, string> > client;
    cin >> n;
    for(int i = 0; i <n ; ++i) {
        cin >> tmp.first >> tmp.second;
        client.push_back(tmp);
    }
    stable_sort(client.begin(), client.end(), cmp);
    for(int i = 0 ; i < n ; ++i)
        cout << client[i].first <<' '<< client[i].second<<'\n';
}