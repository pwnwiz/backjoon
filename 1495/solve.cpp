// https://www.acmicpc.net/problem/1495
// 기타리스트
// Written in C++ langs
// 2020. 10. 14.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int DP[101][1001];
int N, S, M;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> S >> M;
    
    vector<int> v(N+1);
    for(int i=1; i<=N; i++){
        cin >> v[i];
    }
    
    memset(DP, -1, sizeof(DP));
    DP[0][S] = S;
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<=M; j++){
            if(DP[i-1][j] != -1){
                if(DP[i-1][j] + v[i] <= M) DP[i][DP[i-1][j]+v[i]] = DP[i-1][j] + v[i];
                if(DP[i-1][j] - v[i] >= 0) DP[i][DP[i-1][j]-v[i]] = DP[i-1][j] - v[i];
            }
        }
    }
    
    int maxv = -1;
    for(int j=0; j<=M; j++){
        maxv = max(maxv, DP[N][j]);
    }
    
    cout << maxv << "\n";
    
}

