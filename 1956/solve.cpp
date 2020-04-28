// https://www.acmicpc.net/problem/1956
// 운동
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

int V, E;
int MAP[401][401]={0,};

void print(){
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            if(MAP[i][j]>=INF) cout << "INF ";
            else cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
    
}

void floyd(){
    // 경유
    for(int i=1; i<=V; i++){
        // 시작
        for(int j=1; j<=V; j++){
            // 도착
            for(int k=1; k<=V; k++){
                if(i==j || i==k || j==k) continue;
                if(MAP[j][k] > MAP[j][i] + MAP[i][k]){
                    MAP[j][k] = MAP[j][i] + MAP[i][k];
                }
            }
        }
    }
}

int getMin(){
    int mins = INF;
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            if(i==j) continue;
            mins = min(mins, MAP[i][j] + MAP[j][i]);
        }
    }
    return mins;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> V >> E;
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            MAP[i][j] = INF;
        }
    }
    
    int f, t, w;
    for(int i=0; i<E; i++){
        cin >> f >> t >> w;
        MAP[f][t] = w;
    }
    
    floyd();
    int res = getMin();
    if(res >= INF) cout << "-1\n";
    else cout << getMin() << "\n";
}

