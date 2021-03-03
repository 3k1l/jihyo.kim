#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<string, int> table;

bool findTable(string phone) {
    for(int i = 1 ; i < phone.size() ; ++i) {
        if(table.end() != table.find(phone.substr(0,i))) {
            return false;
        }
    }
    table.insert(make_pair(phone, 1));
    return true;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() ; ++i) {
        answer = findTable(phone_book[i]);
        if(answer == false) {
          return answer;
        }
    }
    return answer;
}