// https://www.acmicpc.net/problem/1238
// 파티
// Written in C++ langs
// 2020. 04. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#include <tuple>
#include <math.h>

#define INF 99999999

using namespace std;

int N, M, X;

int MAP[1001][1001]={0,};

void floyd(){
    // 경유
    for(int i=1; i<=N; i++){
        // 시작
        for(int j=1; j<=N; j++){
            if(MAP[j][i] >= INF) continue;
            // 도착
            for(int k=1; k<=N; k++){
                if(i==j || j==k || i==k) continue;
                
                if(MAP[j][k] > MAP[j][i] + MAP[i][k]){
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
    
    cin >> N >> M >> X;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            MAP[i][j] = INF;
        }
    }
    
    int w, x, y;
    for(int i=0; i<M; i++){
        cin >> x >> y >> w;
        MAP[x][y] = w;
    }

    floyd();
    
    int LONGEST = -1;
    for(int i=1; i<=N; i++){
        if(i==X) continue;
        LONGEST = max(LONGEST, MAP[i][X]+MAP[X][i]);
    }

    cout << LONGEST << "\n";
    return 0;
    
}

