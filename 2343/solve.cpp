// https://www.acmicpc.net/problem/2343
// 기타 레슨
// Written in C++ langs
// 2020. 07. 23.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

long long N, M;

long long SIZE = LLONG_MAX;

void bisect(vector<long long> &input, long long l, long long r){
    
    while(l <= r){
        long long mid = (l+r)/2;
        
        int cnt = 0;
        long long remain = 0;
        for(auto in : input){
            if(remain < in){
                remain = mid;
                cnt ++;
            }
            remain -= in;
        }
        
        if(cnt > M){
            l = mid + 1;
        } else {
            r = mid - 1;
            SIZE = min(SIZE, mid);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    vector<long long> input;
    
    long long in;
    long long tc = 0;
    long long minv = 0;
    for(int i=0; i<N; i++){
        cin >> in;
        input.push_back(in);
        tc += in;
        minv = max(minv, in);
    }
    
    bisect(input, minv, tc);
    cout << SIZE << "\n";
    
    return 0;
}

