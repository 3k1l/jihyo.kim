#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Job {
    int idx;
    int priority;
    int time;
    Job(int a, int b, int c) : idx(a), priority(b), time(c) {};
};

struct cmp {
    bool operator()(Job job1, Job job2) {
        if(job1.priority == job2.priority) {
            return job1.time > job2.time ? true : false ;
        }
        else 
            return job1.priority > job2.priority ? false : true;
    }
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<Job, vector<Job>, cmp> outQ;
    queue<Job> tmpQ;
    for(int i = 0 ; i < priorities.size() ; ++i) {
        tmpQ.push(Job(i, priorities[i], i));
    }
    
    int time = priorities.size();
    while(!tmpQ.empty()) {
        ++time;
        Job tmpJob = tmpQ.front();
        
        if(outQ.empty()) {
            outQ.push(Job(tmpJob.idx, tmpJob.priority, tmpJob.time));
            tmpQ.pop();
        }
        else {
            Job outJob = outQ.top();
            if(tmpJob.priority <= outJob.priority) {
                outQ.push(Job(tmpJob.idx, tmpJob.priority, tmpJob.time));
                tmpQ.pop();
            }
            else {
                outQ.pop();
                tmpQ.push(Job(outJob.idx, outJob.priority, time));
            }
        }
    }
    for(int i = 0 ; i < priorities.size() ; ++i) {
        Job job = outQ.top();
        outQ.pop();
        //cout << job.idx<<" ";
        if(job.idx == location)
            answer = i+1;
    }
    return answer;
}