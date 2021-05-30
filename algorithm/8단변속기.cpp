#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int gears[8];
    string answer = "";

    for(int i = 0 ; i < 8 ; ++i) {
        cin >> gears[i];
    }
    for(int i = 1 ; i < 8 ; ++i) {
        if (gears[i-1] == gears[i] -1) {
            if(answer == "descending") {
                answer = "mixed";
                break;
            }
            answer = "ascending";
        }
        else if (gears[i-1] == gears[i] +1) {
            if(answer == "ascending") {
                answer = "mixed";
                break;
            }
            answer = "descending";
        }
    }
    cout << answer << endl;
    return 0;
}