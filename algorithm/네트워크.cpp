#include <string>
#include <vector>

using namespace std;

vector<int> visited;

void dfs(int here,int size, vector<vector<int>> computers) {
    visited[here] = 1;
    for(int there = 0 ; there < size ; ++there) {
        if(!visited[there] && computers[here][there] == 1 ) {
            dfs(there,size, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int cnt = 0;
    int size = computers.size();
    visited = vector<int>(size, 0);
    
    for(int i = 0 ; i < size; ++i) {
        if(!visited[i]) {
            ++cnt;
            dfs(i, size, computers);
        }
    }
    return cnt;
}