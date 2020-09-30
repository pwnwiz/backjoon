// https://www.acmicpc.net/problem/16194
// 카드 구매하기 2
// Written in C++ langs
// 2020. 09. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int P[10001];
int DP[10001];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i=1; i<=N; i++){
        cin >> P[i];
    }
    
    DP[0] = 0;
    DP[1] = P[1];
    
    for(int i=2; i<=N; i++){
        DP[i] = P[i];
        
        for(int j=1; j<=i; j++){
            DP[i] = min(DP[i], DP[j]+DP[i-j]);
        }
    }
    
    cout << DP[N] << "\n";
    
    return 0;
    
}

