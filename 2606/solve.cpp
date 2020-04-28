// https://www.acmicpc.net/problem/2606
// 바이러스
// Written in C++ langs
// 2020. 04. 28.
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

int N, M;

bool MAP[101][101]={0,};

void floyd(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=1; k<=N; k++){
                if(i==j || i==k || j==k) continue;
                if(MAP[j][k] || (MAP[j][i]&& MAP[i][k])){
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
    
    int x, y;
    for(int i=0; i<M; i++){
        cin >> x >> y;
        MAP[x][y] = true;
        MAP[y][x] = true;
    }
    
    floyd();
    int cnt=0;
    for(int i=2; i<=N; i++){
        if(MAP[1][i]) cnt++;
    }
    cout << cnt << "\n";
}

