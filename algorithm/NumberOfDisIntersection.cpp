#include <algorithm>

int solution(vector <int>& A) {
    vector<long long> lower;
    vector<long long> upper;
    int result = 0;

    for(int i = 0 ; i < A.size() ; ++i) {
        lower.push_back((long long)i-A[i]);
        upper.push_back((long long)i+A[i]);
    }
    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());

    int cnt = 0;
    int j = 0;
    for(int i = 0 ; i < lower.size(); ++i) {
        while(lower[i] > upper[j]) {
            --cnt;
            ++j;
        }
        result += cnt;
        ++cnt;
    }
    if (result > 10000000)
        return -1;

    return result;

}