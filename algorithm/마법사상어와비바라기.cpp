#include <iostream>
#include <vector>

using namespace std;
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};


int main() {
    int N,M;
    int boards[51][51];
    vector<pair<int, int> > moves;
    vector<pair<int, int> > clouds;
    int answer = 0;
    cin >> N >> M;
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < N ; ++j) {
            cin >> boards[i][j];
        }
    }
    for(int i = 0 ; i < M ; ++i) {
        int direction, count;
        cin >> direction >> count;
        moves.push_back(make_pair(direction, count));
    }
    //initialize clouds
    clouds.push_back(make_pair(N-1, 0));
    clouds.push_back(make_pair(N-1, 1));
    clouds.push_back(make_pair(N-2, 0));
    clouds.push_back(make_pair(N-2, 1));
    
    for(int i = 0 ; i < moves.size() ; ++i) {
        int direction, count;
        direction = moves[i].first-1;
        count = moves[i].second;
        count %= N;
        //step 1 move clouds
        //cout<<"m "<< i <<endl;
        for(int j = 0 ; j < clouds.size() ; ++j) {
            int newX, newY;
            //cout<<clouds[j].first <<" "<<clouds[j].second  << " rain : "<< boards[clouds[j].first][clouds[j].second]<< endl;
            newX = clouds[j].second + count * dx[direction];
            newY = clouds[j].first + count * dy[direction];
            if(newX < 0) {
                //cout<<"newX "<<newX<<endl;
                newX = N + newX;
            }
            if(newY < 0) {
               //cout<<"newY "<<newX<<endl;
                newY = N + newY;
            }
            if(newX >= N) {
                newX = newX - N;
            }
            if(newY >= N) {
                newY = newY - N;
            }
            clouds[j].first = newY;
            clouds[j].second = newX;
          // cout<<"after : "<<clouds[j].first <<" "<<clouds[j].second  << " rain : "<< boards[clouds[j].first][clouds[j].second]<< endl;
        }
        //step 2 increase cloud's water
        for(int j = 0 ; j < clouds.size() ; ++j) {
            ++boards[clouds[j].first][clouds[j].second];
            //cout<<"after : "<<clouds[j].first <<" "<<clouds[j].second  << " rain : "<< boards[clouds[j].first][clouds[j].second]<< endl;
        }
        //step 3 increase side water
        for(int j = 0 ; j < clouds.size() ; ++j) {
            //check 4 direction
            int rain = 0;
            for(int k = 0 ; k < 4; ++k) {
                int targetX, targetY;
                targetX = clouds[j].second + dx[2*k +1];
                targetY = clouds[j].first + dy[2*k +1];
                if(targetX < 0 || targetX >= N || targetY < 0 || targetY >= N) {
                    continue;
                }
                if(boards[targetY][targetX] > 0) {
                    ++rain;
                }
            }
            boards[clouds[j].first][clouds[j].second] += rain;
            //cout<<"after : "<<clouds[j].first <<" "<<clouds[j].second  << " rain : "<< boards[clouds[j].first][clouds[j].second]<< endl;
        }
        //
        vector<pair<int, int> > tempClouds;
        for(int j = 0 ; j < clouds.size(); ++j) {
            tempClouds.push_back(clouds[j]);
        }
        clouds.clear();
        for(int j = 0 ; j < N ; ++j) {
            for(int k = 0 ; k < N ;++k) {
                bool wasCloud = false;
                if(boards[j][k] < 2) {
                    continue;
                }
                //need to check it was cloud or not
                for(int l = 0 ; l < tempClouds.size() ; ++l) {
                    if(j == tempClouds[l].first && k == tempClouds[l].second) {
                        wasCloud = true;
                        break;
                    }
                }
                if(wasCloud) {
                    continue;
                }
                //make cloud!
                clouds.push_back(make_pair(j,k));
                boards[j][k] -= 2;
            }
        }
        /*
        for(int k = 0 ; k < N ; ++k) {
            for(int j = 0 ; j < N ; ++j) {
                cout<<boards[k][j]<<" ";
            }
            cout<<endl;
        }*/
    }
    // find answer
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < N ; ++j) {
            answer += boards[i][j];
        }
    }
    cout << answer << endl;
    return 0;
}