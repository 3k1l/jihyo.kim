#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

struct carFee{
    string carNum;
    int fee;
    carFee(string tmp1, int tmp2):carNum(tmp1), fee(tmp2) {}
};
struct cmp {
    bool operator()(carFee car1, carFee car2) {
        return car1.carNum > car2.carNum;
    }
};


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, string> carTimeMap; //<carnum, time>
    map<string, string> carINOUTMap; //<carnum, INOUT>
    map<string, int> totalMap; //<carnum, INOUT>
    priority_queue<carFee, vector<carFee>, cmp> pq;

    for(string data : records) {
        //set all data
        string time, carNum, inout,temp;
        time = carNum = inout = temp = "";
        for(int i = 0 ; i < data.length() ; ++i) {
            if(data[i] == ' ') {
                if(time == "") {
                    time = temp;
                }
                else if(carNum == "") {
                    carNum = temp;
                }
                temp = "";
            }
            else {
                temp += data[i];
            }
        }
        inout = temp;
        //calculate data
        map<string, string> :: iterator itINOUT = carINOUTMap.find(carNum);
        map<string, string> :: iterator itTime = carTimeMap.find(carNum);
        map<string, int> :: iterator itTotal = totalMap.find(carNum);

        if (inout == "IN") {
            if(itINOUT == carINOUTMap.end()) {
                carINOUTMap.insert(make_pair(carNum, inout));
                carTimeMap.insert(make_pair(carNum, time));
            }
            else {
                itINOUT->second = inout;
                itTime->second = time;
            }

        }
        else if(inout == "OUT") {
            if(itTime == carTimeMap.end()) {
                cout<<"sth wrong"<<endl;
            }
            else {
                itINOUT->second = inout;
                string inTime = itTime->second;
                int calc = 0;
                //calculate inTime and time
                string inHour = "";
                string inMin = "";
                string temp = "";
                for(int i = 0 ; i < inTime.length() ; ++i) {
                    if(inTime[i] == ':') {
                        inHour = temp;
                        temp = "";
                    }
                    else {
                        temp += inTime[i];
                    }
                }
                inMin = temp;
                //for out
                string outHour, outMin;
                outHour = outMin = temp = "";
                for(int i = 0 ; i < time.length() ; ++i) {
                    if(time[i] == ':') {
                        outHour = temp;
                        temp = "";
                    }
                    else {
                        temp += time[i];
                    }
                }
                outMin = temp;
                int totalInMin = 0;
                int totalOutMin = 0;
                totalInMin = stoi(inHour)*60 + stoi(inMin);
                totalOutMin = stoi(outHour)*60 + stoi(outMin);

                calc = totalOutMin - totalInMin ;

                if(itTotal == totalMap.end()) {
                    totalMap.insert(make_pair(carNum, calc));
                }
                else {
                    itTotal->second += calc;
                }

            }
        } 
    }

        //check it's in or out
        for(auto it : carINOUTMap) {
            if(it.second == "IN") {
                map<string, string> :: iterator itTime = carTimeMap.find(it.first);  
                map<string, int> :: iterator itTotal = totalMap.find(it.first);
                string inTime = itTime->second;
                int calc = 0;
                string inHour = "";
                string inMin = "";
                string temp = "";
                for(int i = 0 ; i < inTime.length() ; ++i) {
                    if(inTime[i] == ':') {
                        inHour = temp;
                        temp = "";
                    }
                    else {
                        temp += inTime[i];
                    }
                }
                inMin = temp;
                int totalInMin = 0;
                totalInMin = stoi(inHour)*60 + stoi(inMin);
                int totalOutMin = 23*60 + 59;
                calc = totalOutMin - totalInMin;
                if(itTotal == totalMap.end()) {
                    totalMap.insert(make_pair(it.first, calc));
                }
                else {
                    itTotal->second += calc;
                }
            }
        }
        //pay!
        int baseMinute = fees[0];
        int basePrice = fees[1];
        int intervalMinute = fees[2];
        int interalPrice = fees[3];
        int feeResult = 0;
        for(auto it : totalMap) {
            if(it.second < baseMinute) {
                feeResult = basePrice;
            }
            else {
                int timeVal = ceil((it.second -baseMinute) / float(intervalMinute));
                feeResult = basePrice + timeVal * interalPrice;
            }
            carFee car(it.first, feeResult);
            pq.push(car);
        }
    while(!pq.empty()) {
        carFee car = pq.top();
        pq.pop();
        answer.push_back(car.fee);
    }
    return answer;
}