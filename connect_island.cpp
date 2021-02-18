#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int parent[100];

bool cmp(vector<int> edge1, vector<int> edge2) {
    return edge1[2] < edge2[2];
}

int getParent(int node) {
    if(node == parent[node])
        return node;
    else
        return getParent(parent[node]);
}

bool isCycle(vector<int> edge) {
    int parent1 = getParent(edge[0]);
    int parent2 = getParent(edge[1]);
    if(parent1 == parent2)
        return true;
    else
        return false;
}
void unionParent(int node1, int node2){
	node1 = getParent(node1);
	node2 = getParent(node2);
	if(node1<node2) {
        parent[node2] = node1;
    }
	else {
        parent[node1] = node2;
    }
}
int solution(int n, vector<vector<int> > costs) {
    int answer = 0;
    //initialize parent node
    for(int i = 0 ; i < n ; ++i) {
        parent[i] = i;
    }
    sort(costs.begin(), costs.end(), cmp);

    for(int i = 0 ; i < n ; ++i) {
        //cout <<costs[i][0]<<costs[i][1]<<costs[i][2]<<"\n";
        if(!isCycle(costs[i])) {
            answer += costs[i][2];
            unionParent(costs[i][0],costs[i][1]);
        }
    }
    return answer;
}