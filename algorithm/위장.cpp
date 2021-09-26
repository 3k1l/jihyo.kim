#include <string>
#include <vector>
#include <unordered_map>
#define MAX_CLOTHES 30
using namespace std;

int solution(vector<vector<string> > clothes) {
    int answer = 1;
    unordered_map<string, int> catagory;
    for(int i = 0 ; i < clothes.size() ; ++i) {
        catagory[clothes[i][1]]++;
    }
    for(pair<string ,int> atom: catagory) {
        answer *= (atom.second+1);
    }
    answer--;
    return answer; 
}