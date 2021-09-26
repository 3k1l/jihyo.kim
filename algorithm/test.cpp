#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int N, K;
int visit[500001][2];
queue<pair<int, int> > q; // <위치, 시간>

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	visit[N][0] = true;
	q.push(make_pair(N,0));

	while (!q.empty())
	{
		int now = q.front().first;
		int time = q.front().second;
		int pos = K + time * (time + 1) / 2;
		q.pop();

		if (pos > 500000)
		{
			cout << -1 << '\n';
			break;
		}

		if (now == pos || visit[pos][time%2])
		{
			cout << time << '\n';
			break;
		}
        int next;
        if(now > 0) {
            next = now-1;
            if(!visit[next][(time+1)%2]) {
                q.push(make_pair(next,time + 1));
				visit[next][(time+1)%2] = true;
            }
        }
        if(now < 500000) {
            next = now+1;
            if(!visit[next][(time+1)%2]) {
                q.push(make_pair(next,time + 1));
				visit[next][(time+1)%2] = true;
            }
        }
        if(now <= 250000) {
            next = now*2;
            if(!visit[next][(time+1)%2]) {
                q.push(make_pair(next,time + 1));
				visit[next][(time+1)%2] = true;
            }
        }
		
	}
}