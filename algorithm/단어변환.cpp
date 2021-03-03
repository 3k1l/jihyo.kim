#include <string>
#include <vector>

using namespace std;
int answer = 100;
int checked[50] = {0,};

int checkDiff(string begin, string word) {
    int cnt = 0;
    for(int i = 0; i < begin.size() ;  ++i) {
        if(begin[i] != word[i])
            ++cnt;
        if(cnt > 1){
            return 0;
        }
    }
    if (cnt == 1)
        return 1;
    else
        return 0;
}

void dfs(string begin, string target, vector <string> words, int depth) {
    if(begin == target){
        answer = min(answer, depth);
        return;
    }
    for(int i = 0 ; i < words.size() ; ++i) {
        if(checked[i] == 0) {
            if(checkDiff(begin, words[i]) == 1) {
                checked[i] = 1;
                dfs(words[i], target, words, depth+1);
                checked[i] = 0;
            }
        }
    }
    return;
}
int solution(string begin, string target, vector<string> words) {
    int depth = 0;

    dfs(begin, target, words, depth);
    if(answer == 100)
        return 0;
    else 
        return answer;
}