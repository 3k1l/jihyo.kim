#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

long long bfs(int** connected, vector<int> a, int node) {
    vector<int> tempA = a;
    queue<int> q;
    q.push(node);
    long long result = 0;
    long long sum = 0;
    int first, second;
    while(!q.empty()) {
        node = q.back();
        q.pop();
        //sum += node;
        //how to increase result;
        for(int i = 0 ; i < a.size() ;++i) {
            if(connected[node][i] == 1) {
                q.push(i);
                first = a[node] > 0 ? a[node] : -a[node];
                second = a[i] > 0 ? a[i] : -a[i];
                if(first > second) {

                }
            }
        }
    }
    return result;
}

long long solution(vector<int> a, vector<vector<int> > edges) {
    long long answer = 0;
    long long sum = 0;
    int** connected = new int*[a.size()];
    vector<int> nodes;
    int connectedCnt = 0;
    
    //first check this is possible
    for(int i = 0 ; i < a.size() ; ++i) {
        sum += a[i];
        connected[i] = new int[a.size()];
    }
    if(sum != 0 ) {
        answer = -1;
        return answer;
    }    
    //initialize connect
    for(int i = 0 ; i < edges.size() ; ++i) {
        connected[edges[i][0]][edges[i][1]] = 1;
        connected[edges[i][1]][edges[i][0]] = 1;
    } 
    for(int i = 0 ; i < a.size() ; ++i) {
        connectedCnt = 0;
        for(int j = 0 ; j < a.size() ;++j) {
            if(connected[i][j] == 1)
                ++connectedCnt;
        }
        if(connectedCnt == 1) {
            nodes.push_back(i);
        }
    }
    for(int i = 0 ; i < nodes.size() ; ++i) {
        if(i == 0)
            answer = bfs(connected, a, i);
        answer = min(answer, bfs(connected, a, i));
    }
    //free
    for(int i = 0 ; i < a.size() ;++i ) {
        delete[] connected[i];
    }
    delete[] connected;
    return answer;
}