// https://www.acmicpc.net/problem/2458
// 키 순서
// Written in C++ langs
// 2020. 06. 01.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <limits.h>

using namespace std;

int N;
int M;

bool MAP[501][501]={0,};

void floyd(){
    // 경유, 시작, 도착
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=1; k<=N; k++){
                if(i==j || j==k || i==k) continue;
                if(MAP[j][k] || (MAP[j][i] && MAP[i][k])){
                    MAP[j][k] = true;
                }
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        MAP[a][b] = true;
    }
    
    floyd();
    
    int cnt = 0;
    for(int i=1; i<=N; i++){
        bool flag = true;
        for(int j=1; j<=N; j++){
            // 본인 제외
            if(i==j) continue;
            
            // 본인에게 도달하는 경로가 존재하거나 본인이 그 경로로 도달할 수 있어야 됨
            if(!MAP[i][j] && !MAP[j][i]){
                flag = false;
            }
        }
        if(flag) cnt++;
    }
    
    cout << cnt << "\n";
    
    return 0;
    
}

