// you can use includes, for example:
 #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int result,begin;
    int size = A.size();
    result = 0;
    begin = 1;
    sort(A.begin(),A.end());
    if (size == 0 || size == 1)
        return size;
        
    for (int i = 0 ; i < size; ++i){
        if (begin){
            ++result;
        }
        if(i != size-1){
            if (A[i] == A[i+1])
                begin = 0;
            else
                begin = 1;
        }

    }
    return result;
}