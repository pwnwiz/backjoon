// https://www.acmicpc.net/problem/2294
// 동전 2
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
    
    for(int i=1; i<=K; i++){
        DP[i] = 10001;
    }

    DP[0] = 1;
    for(int i=1; i<=N; i++){
        for(int j=COIN[i]; j<=K; j++){
            if(COIN[i] == j) DP[j] = 1;
            DP[j] = min(DP[j], DP[j - COIN[i]] + DP[COIN[i]]);
        }
    }
    
    (DP[K] == 10001) ? cout << "-1\n" : cout << DP[K] << "\n";
    
    return 0;
    
}

