#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int num = 9;
    int sum = 0, targetSum;
    int people[num];
    for(int i = 0 ; i < num ; ++i) {
        cin >> people[i];
        sum += people[i];
    }
    //solution
    sort(people, people+num);
    targetSum = sum - 100;
    bool findAnswer = false;
    int targetNum1, targetNum2;

    for(int i = 0 ; i < num ; ++i) {
        for(int j = i+1 ; j < num ; ++j) {
            if(targetSum == (people[i] + people[j])) {
                findAnswer = true;
                targetNum1 = people[i];
                targetNum2 = people[j];
                break;
            }
        }
        if(findAnswer) {
            break;
        }
    }
    //print out answer
    for(int i = 0 ; i < num ; ++i) {
        if(people[i] != targetNum1 && people[i] != targetNum2) {
            cout<< people[i]<<endl;
        }
    }
    return 0;
}