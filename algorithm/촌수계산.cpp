#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<int> relations[101];
bool visited[101] = {false};
int distanceNum[101] = {0};

int solution(int peopleNum, int num1, int num2, int relationCount) {
    queue<int> findQ;
    int countNum = 1;
    int num, answer;
    findQ.push(num1);
    answer = -1;
    while(!findQ.empty()) {
        num = findQ.front();
        findQ.pop();
        countNum = distanceNum[num]+1;
        visited[num] = true;
        if(num == num2) {
            answer = distanceNum[num];
            break;
        }
        for(int i = 0 ; i < relations[num].size(); ++i) {
            if(!visited[relations[num][i]]) {
                findQ.push(relations[num][i]);
                distanceNum[relations[num][i]] = countNum;
            }   
        }
    }
    return answer;
}

int main() {
    int peopleNum, num1, num2, relationCount, parentNum, childNum;
    cin >> peopleNum >> num1 >> num2 >> relationCount;

    for(int i = 0 ; i < relationCount ; ++i) {
        cin >> parentNum >> childNum;
        relations[parentNum].push_back(childNum);
        relations[childNum].push_back(parentNum);
    }
    printf("%d\n", solution(peopleNum, num1, num2, relationCount));
    return 0;
}