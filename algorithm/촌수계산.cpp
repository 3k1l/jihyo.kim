#include <iostream>

using namespace std;
int parent[100];
int solution(int peopleNum, int num1, int num2, int relationCount, pair<int, int> relations[100]) {
    //tree 구조로 추가
    int result = -1;
    if(getRoot(num1) == getRoot(num2)) {
        //
    }
    else
        return -1;
}

int getRoot(int child) {
    if(parent[child] == child)
        return child;
    else
        return getRoot(parent[child]);
}

int main() {
    int peopleNum, num1, num2, relationCount, parentNum, childNum;
    pair<int ,int> relations[100];
    scanf("%d %d %d %d", &peopleNum, &num1, &num2, &relationCount);

    for(int i = 0  ; i < 100 ; i++)
        parent[i] = i;

    for(int i = 0 ; i < relationCount ; ++i) {
        scanf("%d %d", &parentNum, &childNum);
        relations[i] = make_pair(parentNum, childNum);
        parent[childNum] = parentNum;
    }
    printf("%d\n", solution(peopleNum, num1, num2, relationCount, relations));
    return 0;
}