int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int cnt = 0;
    vector<int> pre_sum(A.size(),0);

    for(int i = 0 ; i < (int)A.size() ; ++i){
        pre_sum[i] = pre_sum[i-1]+A[i];
    }

    for(int i = 0; i < A.size(); ++i){
        if(A[i] == 0){
            cnt += (pre_sum[A.size()-1] - pre_sum[i]);
        }
        if(cnt > 1000000000)
        		return -1;
    }
    return cnt;
}