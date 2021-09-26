#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    vector<pair<int, int> > edges[V+1];
    int from, to, cost;
    for(int i = 0 ; i < E ; ++i) {
        scanf("%d %d %d", &from, &to, &cost);
        edges[from].push_back(make_pair(to, cost));
    }
    //pq first node is cost, second is node. we check smallest cost and node
    priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; 
    int dist[V+1];
    fill(dist, dist+V+1, 1e9);
    //make dist table
    int start = 0;
    //start point is always 0
    dist[start] = 0;
    pq.push(make_pair(0,start));
    while(!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        //now update all dist table which smaller cost (nextNode which is connected node )
        for(int i = 0 ; i < edges[node].size(); ++i) {
            int nextNode = edges[node][i].first;
            int nextCost = edges[node][i].second;
            if(dist[nextNode] > cost + nextCost) {
                dist[nextNode] = dist[node] + nextCost;
                pq.push(make_pair(dist[nextCost], nextNode));
            }
        } 
    }

    return 0;
}