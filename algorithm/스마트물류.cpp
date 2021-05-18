#include<iostream>
#include<queue>

using namespace std;
bool visited[20001] ={false};
string belt;
int dx[2] = {-1, 1};
int dfs(int x, int k) {
    queue<int> q;
    int num, index;
    q.push(x);
    num = 0;
    while(!q.empty()) {
        index = q.front();
        
        for(int i = 0 ; i < 2 ; ++i) {
            int newIndex = dx[i]+index;
            if(newIndex  >= 0 && newIndex < k) {
                if(belt[newIndex] != 'P' && !visited[newIndex]) {
                    q.push(newIndex);
                }
            }
        }
    }
    return num;
}

int main(int argc, char** argv)
{
    int k, n;
    cin>>k >>n;
    cin>>belt;
    int num,numMax;
    numMax = 0;
    for(int i = 0 ; i < k ; i++) {
        if( belt[i] == 'P' && visited[i]) {
            num = dfs(i, k);   
            numMax = max(num, numMax);             
        }
    }
    cout<<numMax<<endl;
 return 0;
}