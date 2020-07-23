// https://www.acmicpc.net/problem/3079
// 입국심사
// Written in C++ langs
// 2020. 07. 23.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

long long N, M;
long long T = LLONG_MAX;

void bisect(vector<long long> &pass, long long l, long long r){
    while(l <= r){
        
        // 걸리는 시간
        long long mid = (l + r) / 2;
        
        long long cnt = 0;
        for(auto p : pass){
            cnt += (mid / p);
        }
        
        // 시간 내에 사람을 다 처리할 수 있다면
        if(cnt >= M){
            r = mid - 1;
            T = min(T, mid);
        } else {
            l = mid + 1;
        }
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    vector<long long> pass;
    
    long long in;
    long long maxv = 0;
    for(int i=0; i<N; i++){
        cin >> in;
        pass.push_back(in);
        maxv = max(maxv, in);
    }
    
    // 범위 문제가 발생할 수 있어서 최댓값을 계산해 주는 것이 좋음
    // LLONG_MAX로 넣거나 값을 거의 MAX에 가깝게 둘 경우 Overflow 발생
    T = maxv * M;
    bisect(pass, 1, T);
    cout << T << "\n";
    
    return 0;
}

