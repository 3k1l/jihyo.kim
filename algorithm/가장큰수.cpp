#include <string>
#include <vector>
#include <algorithm>
//2 25 25 2
//2 20 2 20
//2 251 251 2
//2 250 250 2
//2 210 2 210
//99 991 99 991 991 99
//112 113 113 112
using namespace std;
bool cmp(string first, string second){
    if(first+second > second+first)
        return true;
    else return false;
    
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> stringNumbers;
    for(int num : numbers)
        stringNumbers.push_back(to_string(num));
    sort(stringNumbers.begin(), stringNumbers.end(), cmp);
    for(string str : stringNumbers ) {
        if(answer == "" && str =="0")
            continue;
        else
            answer = answer + str;
    }
    if(answer =="")
        answer = "0";
    return answer;
}
//30 3. 3 30
//3 30. 3 30
// 10 100 10010 or 10100