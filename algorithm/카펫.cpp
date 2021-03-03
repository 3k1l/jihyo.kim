#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    //row is bigger or same than col
    int yellowRow, yellowCol;
    yellowRow = yellowCol = 0;
    //yellowRow * yellowCol == yellow;
    //2(yellowRow + yellowCol) + 4 == brown;
    while(true) {
        yellowCol++;
        if(yellow % yellowCol != 0) {
            continue;
        }
        else {
            yellowRow = yellow / yellowCol;
        }
        if((yellowRow + yellowCol)*2 + 4 == brown)
            break;
    }
    answer.push_back(yellowRow+2);
    answer.push_back(yellowCol+2);
    return answer;
}