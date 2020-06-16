// https://www.acmicpc.net/problem/11404
// 플로이드
// Written in C++ langs
// 2020. 06. 16.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int N, M;
int MAP[101][101];

void floyd(){
    // 경유
    for(int i=1; i<=N; i++){
        // 시작
        for(int j=1; j<=N; j++){
            // 도착
            for(int k=1; k<=N; k++){
                if(i==j || j==k || i==k) continue;
                if(MAP[j][i] != INT_MAX && MAP[i][k] != INT_MAX){
                    MAP[j][k] = min(MAP[j][k], MAP[j][i] + MAP[i][k]);
                }
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(i==j) continue;
            MAP[i][j] = INT_MAX;
        }
    }
    
    cin >> N;
    cin >> M;
    
    int a, b, c;
    for(int m=0; m<M; m++){
        cin >> a >> b >> c;
        if(MAP[a][b] != INT_MAX){
            MAP[a][b] = min(MAP[a][b], c);
        } else {
            MAP[a][b] = c;
        }
    }
    
    floyd();
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(MAP[i][j] == INT_MAX) MAP[i][j] = 0;
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
    
    
    return 0;
    
}

