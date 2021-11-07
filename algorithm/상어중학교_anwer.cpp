#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stdio.h>
 
#define MAX 25
using namespace std;
 
struct BLOCK
{
    int Size;
    int Rainbow_Cnt;
    int x;
    int y;
    vector<pair<int, int> > Block_Pos;
};
 
int N, M, Answer;
int MAP[MAX][MAX];
bool Visit[MAX][MAX];
bool R_Visit[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0 ,0 };
 
void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
 
bool Cmp(pair<int, int> A, pair<int, int> B)
{
    if (A.first <= B.first)
    {
        if (A.first == B.first)
        {
            if (A.second < B.second)
            {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}
 
BLOCK BFS(int a, int b, int Color)
{
    memset(R_Visit, false, sizeof(R_Visit));
    vector<pair<int, int> > Block;
    vector<pair<int, int> > Except_Rainbow_Block;
    queue<pair<int, int> > Q;
    Block.push_back(make_pair(a, b));
    Except_Rainbow_Block.push_back(make_pair(a, b));
    Q.push(make_pair(a, b));
    Visit[a][b] = true;
    int Rainbow = 0;
 
    while (Q.empty() == false)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if (MAP[nx][ny] == 0)
                {
                    if (R_Visit[nx][ny] == false)
                    {
                        R_Visit[nx][ny] = true;
                        Rainbow++;
                        Block.push_back(make_pair(nx, ny));
                        Q.push(make_pair(nx, ny));
                    }
                }
                else if(MAP[nx][ny] == Color)
                {
                    if (Visit[nx][ny] == false)
                    {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(nx, ny));
                        Block.push_back(make_pair(nx, ny));
                        Except_Rainbow_Block.push_back(make_pair(nx, ny));
                    }
                }
            }
        }
    }
 
    sort(Except_Rainbow_Block.begin(), Except_Rainbow_Block.end(), Cmp);
    BLOCK R_Block;
    R_Block.Size = Block.size();
    R_Block.Rainbow_Cnt = Rainbow;
    R_Block.x = Except_Rainbow_Block[0].first;
    R_Block.y = Except_Rainbow_Block[0].second;
    R_Block.Block_Pos = Block;
    return R_Block;
}
 
bool Compare_Block(BLOCK A, BLOCK B)
{
    if (A.Size >= B.Size)
    {
        if (A.Size == B.Size)
        {
            if (A.Rainbow_Cnt >= B.Rainbow_Cnt)
            {
                if (A.Rainbow_Cnt == B.Rainbow_Cnt)
                {
                    if (A.x >= B.x)
                    {
                        if (A.x == B.x)
                        {
                            if (A.y > B.y)
                            {
                                return true;
                            }
                            return false;
                        }
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}
 
BLOCK Find_Biggest_Block()
{
    memset(Visit, false, sizeof(Visit));
    BLOCK Result;
    Result.Size = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Visit[i][j] == true) continue;
            if (MAP[i][j] == -1 || MAP[i][j] == -2 || MAP[i][j] == 0) continue;
            BLOCK Temp_Result = BFS(i, j, MAP[i][j]);
 
            if (Result.Size == -1) Result = Temp_Result;
            else
            {
                if (Compare_Block(Temp_Result, Result) == true) Result = Temp_Result;
            }
        }
    }
    return Result;
}
 
void Delete_Block(BLOCK Result)
{
    vector<pair<int, int> > V = Result.Block_Pos;
    for (int i = 0; i < V.size(); i++)
    {
        int x = V[i].first;
        int y = V[i].second;
        MAP[x][y] = -2;
    }
    //cout<<(V.size() * V.size())<<endl;
    Answer += (V.size() * V.size());
}
 
void gravity() {
    for(int i  = N-1 ; i >= 0 ; --i) {
        for(int j = 0 ; j < N ; ++j) {
            if(MAP[i][j] == -1) {
                continue;
            }
            if(MAP[i][j] == -2) {
                continue;
            }
            for(int k = i+1 ; k < N ; ++k) {
                if(MAP[k][j] == -2) {
                    MAP[k][j] = MAP[k-1][j];
                    MAP[k-1][j] = -2;
                }
                else {
                    break;
                }
            }
        }
    }
}

void rotate() {
    int temp[21][21];
    for(int i = 0 ; i < N ;++i) {
        for(int j = 0 ; j < N ; ++j) {
            temp[i][j] = MAP[i][j];
        }
    }
    for(int col = N-1 ; col >= 0 ; --col) {
        for(int row = 0 ; row < N ; ++row) {
            MAP[N-1-row][col] = temp[col][row];
        }
    }   
}

void print() {
    cout<<endl;
    for(int i  = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < N ; ++j) {
            cout << MAP[i][j]<<" ";
        }
        cout<<endl;
    };
    cout<<endl;
}

void Solution()
{
    while (1)
    {
        BLOCK Result = Find_Biggest_Block();
        if (Result.Size < 2) break;
        Delete_Block(Result);
        cout<<"a"<<endl;
        print();
        gravity();
        cout<<"b"<<endl;
        //print();
        rotate();
        cout<<"c"<<endl;
        //print();
        gravity();
        cout<<"d"<<endl;
        print();
    }
    cout << Answer << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
