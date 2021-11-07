#include<iostream>
#include<vector>
using namespace std;

struct Info {
	int to;
	int speed;
};

int main(int argc, char** argv)
{
	int answer = 0;
	int N, M;
	cin >> N >> M;
	int cur = 0;
	vector<Info> standard;
	vector<Info> run;
	for(int i = 0 ; i < N ; ++i) {
		int a,b;
		cin >> a >> b;
		Info info;
		info.to = cur+ a;
		info.speed = b;
		cur += a;
		standard.push_back(info);
	}
	cur = 0;
	for(int i = 0 ; i < M ; ++i) {
		int a,b;
		cin >> a >> b;
		Info info;
		info.to = cur+ a;
		info.speed = b;
		cur += a;
		run.push_back(info);
	}
	int targetS, targetR;
	targetS = targetR = 0;
	for(int i = 0 ; i < 100 ; ++i) {
		if(i > standard[targetS].to) {
			targetS++;
		}
		if(i > run[targetR].to) {
			targetR++;
		}
		int result = 0;
		result = run[targetR].speed - standard[targetS].speed;
		if(result < 0) {
			result = 0;
		}
		answer = max(answer, result);
	}
	cout<<answer;
	return 0;
}