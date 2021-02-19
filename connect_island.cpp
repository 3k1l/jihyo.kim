#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
    int num;
    Node* parent;
    vector<Node*> children;
    int childrenNum;
    Node(int _num) : parent(this), childrenNum(0), num(_num) {}

    void insert(Node* child) {
        children.push_back(child);
        ++childrenNum;
    }
};

bool isCycle(Node* node1, Node* node2) {
    if(node1->parent == node2->parent)
        return true;
    else
        return false;
}
void setChild(Node* node1, Node* node2) {
    node2->parent = node1;
    node1->insert(node2);
}

Node* getParent(Node* node1) {
    if(node1->parent->num == node1->num)
        return node1;
    else {
        return getParent(node1->parent);
    }
}

void makeEdge(Node* node1, Node* node2) {
    if(getParent(node1) < getParent(node2)) {
        setChild(node1, node2);
    }
    else {
        setChild(node2, node1);
    }
}

bool cmp(vector<int> num1, vector<int> num2) {
    return num1[2] < num2[2];
}

int solution(int n, vector<vector<int> > costs) {
    int answer = 0;
    int idxStart, idxEnd, distance;
    sort(costs.begin(), costs.end(), cmp);
    vector<Node> nodes;
    for(int i = 0 ; i < n ; ++i) {
        nodes.push_back(Node(i));
    }

    for(int i = 0 ; i < n; ++i) {
        idxStart = costs[i][0];
        idxEnd = costs[i][1];
        distance = costs[i][2];
        if(!isCycle(&nodes[idxStart], &nodes[idxEnd])) {
            makeEdge(&nodes[idxStart], &nodes[idxEnd]);
            answer += distance;
        }
    }
    return answer;
}