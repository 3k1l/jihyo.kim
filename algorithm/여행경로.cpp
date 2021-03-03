#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> answer;

bool dfs(vector<vector<string>> tickets, string from, vector<bool> visited, vector<string> path) {
    int size = tickets.size();
    bool visitAll = true;
    path.push_back(from);

    for(int i = 0 ; i < tickets.size(); ++i){
        if(!visited[i]) {
            visitAll = false;
            break;
        }   
    }
    if(visitAll){
        answer = path;
        return true;
    }
    
    for(int i = 0 ; i < size ; ++i ) {
        if(tickets[i][0] == from){
            if(!visited[i]) {
                visited[i] = true;
                bool success = dfs(tickets, tickets[i][1], visited, path);
                if(success)
                    return true;
                visited[i] = false;
            }
        }
    }
    path.pop_back();
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<bool> visited = vector<bool>(tickets.size(), false);
    vector<string> path;
    sort(tickets.begin(), tickets.end());
    dfs(tickets, "ICN", visited, path);
    return answer;
}