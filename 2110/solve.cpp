// https://www.acmicpc.net/problem/2110
// 공유기 설치
// Written in C++ langs
// 2020. 02. 27.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int K, N;
long long HOUSE[1000001]={0,};
long long H=0;
long long idx=0;

bool checkRouter(long long val){
    long long start = HOUSE[0];
    int router = 1;
    for(long long i=1; i<K; i++){
        long long dest = HOUSE[i] - start;
        if(dest >= val){
            router++;
            start = HOUSE[i];
        }
        if(router >= N) return true;
    }
    return false;
}

void bisect(long long begin, long long end){
    if(end - begin <=1){
        H = begin;
    }
    else{
        long long mid = (begin+end)/2;
        
        if(!checkRouter(mid)){
            return bisect(begin, mid);
        }
        else{
            return bisect(mid, end);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N;
    for(long long i=0; i<K; i++){
        cin >> HOUSE[i];
    }
    
    sort(HOUSE, HOUSE+K);
    bisect(1, HOUSE[K-1]-HOUSE[0]);
    cout << H << "\n";
    
    return 0;
    
}

