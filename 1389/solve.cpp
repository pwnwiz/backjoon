// https://www.acmicpc.net/problem/1389
// 케빈 베이컨의 6단계 법칙
// Written in C++ langs
// 2020. 04. 15.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <tuple>
#define INF 5000

using namespace std;

int N, C;
int MAP[101][101] = {0,};
int MIN_VAL = 5000;
int MIN_IDX = 0;

void floyd(){
    // 경유
    for(int i=1; i<=N; i++){
        // 시작
        for(int j=1; j<=N; j++){
            // 도착
            for(int k=1; k<=N; k++){
                if(i==j || i==k || j==k) continue;
                if(MAP[j][k] > MAP[j][i]+MAP[i][k]){
                    MAP[j][k] = MAP[j][i] + MAP[i][k];
                }
            }
        }
    }
    
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> N >> C;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            MAP[i][j] = INF;
        }
    }
    
    int a, b;
    for(int i=0; i<C; i++){
        cin >> a >> b;
        MAP[a][b] = 1;
        MAP[b][a] = 1;
    }
    
    floyd();
    
    for(int i=1; i<=N; i++){
        int val = 0;
        for(int j=1; j<=N; j++){
            if(i==j) continue;
            if(MAP[i][j]!=INF){
                val += MAP[i][j];
            }
        }
        if(val < MIN_VAL){
            MIN_IDX = i;
        }
        MIN_VAL = min(MIN_VAL, val);
    }
    
    cout << MIN_IDX << "\n";
    
    return 0;
    
}

