// https://www.acmicpc.net/problem/2293
// 동전 1
// Written in C++ langs
// 2020. 04. 06.
// Wizley

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int DP[10001]={0,};
int COIN[101]={0,};

int N;
int K;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    
    for(int i=1; i<=N; i++){
        cin >> COIN[i];
    }
    
    DP[0] = 1;
    for(int i=1; i<=N; i++){
        for(int j=COIN[i]; j<=K; j++){
            DP[j] += DP[j - COIN[i]];
        }
    }
    
    cout << DP[K] << "\n";

    return 0;
    
}

