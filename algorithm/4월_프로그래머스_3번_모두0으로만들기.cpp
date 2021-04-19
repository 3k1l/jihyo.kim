#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

long long answer = 0;
vector <int> tree[300002];
vector <long long> A;

void dfs(int cur, int before) {
    for(int next : tree[cur]) {
       if(next == before)
           continue;
        dfs(next, cur);
        answer += abs(A[next]);
        A[cur] += A[next];
        A[next] = 0;
    }
}

long long solution(vector<int> a, vector<vector<int> > edges) {
    //first check this is possible
    for(int i = 0 ; i < a.size() ; ++i) {
        A.push_back(a[i]);
        answer += A[i];
    }
    if(answer != 0 ) {
        return -1;
    } 
    //initialize
    for(int i = 0 ; i < edges.size() ; ++i) {
        tree[edges[i][0]].push_back(edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
    }
    // find answer
    dfs(0, -1);
    return answer;
}