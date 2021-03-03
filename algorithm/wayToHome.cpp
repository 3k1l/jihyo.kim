#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int distance[101][101] = {0};
    int board[101][101] = {1};
    
    for(int i = 0 ; i< puddles.size(); ++i)
        board[puddles[i][0]][puddles[i][1]] = -1;
    distance[1][0] = 1;
    for(int i = 1 ; i <= m ; ++i) {
        for(int j = 1 ; j <= n ; ++j) {
            if(board[i][j] == -1)
                distance[i][j] = 0;
            else 
                distance[i][j] = (distance[i-1][j] + distance[i][j-1]) % 1000000007;
        }
    }
    return distance[m][n];
}