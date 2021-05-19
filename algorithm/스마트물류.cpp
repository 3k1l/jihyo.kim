#include<iostream>

using namespace std;
bool visited[20001] ={false};
string belt;
int main(int argc, char** argv)
{
    int k, n;
    cin >> n >> k;
    cin >> belt;
    int num, answer;
    answer = 0;
    int newIndex;
    for(int i = 0 ; i < n ; i++) {
        if( belt[i] == 'P') {
            for(int j = -k ; j <= k ;++j) {
                newIndex = i + j;
                if(newIndex >= 0 && newIndex < n) {
                    if(belt[newIndex] == 'H' && !visited[newIndex]) {
                        ++answer;
                        visited[newIndex] = true;
                        break;
                    }
                }
            }  
        }
    }
    cout<<answer<<endl;
 return 0;
}