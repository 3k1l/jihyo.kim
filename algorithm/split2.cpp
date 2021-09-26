#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string str = "value1 value2 value3 value4";

    istringstream ss(str);

    string strBuffer, reverseStr;

    vector<string> vec;

    while(getline(ss, strBuffer, ' ')) {

        vec.push_back(strBuffer);
        cout<< strBuffer << endl;
        reverseStr = strBuffer;
        reverse(reverseStr.begin(), reverseStr.end());
        cout<< reverseStr<<endl;
    }
}
