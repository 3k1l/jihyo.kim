#include <string>
#include <vector>
#include <iostream>

using namespace std;

void push_heap(vector<int> heap, int node) {
    heap.push_back(node);
    int idx = heap.size()-1;
    while(idx>0) {
        int parent = (idx-1)/2;
        if(heap[parent] > heap[idx]) {
            swap(heap[parent], heap[idx]);
            idx = parent;
        }
        else {
            break;
        }
    }
}

int pop_heap(vector<int> heap) {
    int value = heap[0];
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    int idx = 0;
    int smallest_i = idx;
    while(true) {
        int left = (idx+1)*2 -1;
        int right = (idx+1)*2;
        if(left < heap.size() && heap[left] < heap[smallest_i]) {
            swap(heap[left], heap[idx]);
            smallest_i = left;
            idx = left;
        }
        if(right < heap.size() && heap[right] < heap[smallest_i]) {
            swap(heap[right], heap[idx]);
            smallest_i = right;
            idx = right;
        }
        if(idx == smallest_i)
            break;
    }
    return value;
}
int solution(vector<int> scoville, int K) {
    int answer = 0;
    vector<int> heap;
    for(int value : scoville)
        push_heap(heap, value);

    while(heap.front() < K) {
        if(heap.size()<2) {
            answer = -1;
            break;
        }
        int smallest = pop_heap(heap);
        cout<<smallest<<endl;
        int secondSmall = pop_heap(heap);
        push_heap(heap, smallest + secondSmall*2);
        ++answer;
    }
    return answer;
}