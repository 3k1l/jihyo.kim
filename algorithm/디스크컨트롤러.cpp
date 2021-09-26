#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct Disk {
    int start;
    int size;
    Disk(int x, int y) : start(x), size(y) {}
};

struct cmp {
    bool operator()(Disk disk1, Disk disk2) {
        if(disk1.size > disk2.size)
            return true;
        else 
            return false;
    }
};

int solution(vector<vector<int> > jobs) {
    int answer = 0;
    int sum = 0;
    //sort the jobs with the start time
    sort(jobs.begin(), jobs.end());
    //make pq 
    priority_queue <Disk, vector<Disk>, cmp> pq;
    
    int time = 0;
    int idx = 0;
    while(true) {
        // condition to come out this loop
        if(idx == jobs.size() && pq.empty()) {
            break;
        }
        //push any disk that meets times
        for(int i = idx; i < jobs.size() ; ++i ) {
            if(jobs[i][0] <= time) {
                pq.push(Disk(jobs[i][0], jobs[i][1]));
                idx++;
            }
            else {
                break;
            }     
        }
        
        if(!pq.empty()) {
            //pop the shortest disk
            Disk topDisk = pq.top();
            pq.pop();
            //update time           
            time = time + topDisk.size;
            sum = sum + (time - topDisk.start);

        }
        else { // there is nothing yet
            time++;
        }
    }
    //calculate final answer;
    answer = sum/jobs.size();
    return answer;
}