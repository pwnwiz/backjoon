// https://www.acmicpc.net/problem/10159
// 저울
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
int MAP[101][101]={0,};

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
                if(MAP[j][k]==1 || (MAP[j][i]==1 && MAP[i][k]==1)){
                    MAP[j][k] = 1;
                }
                else if(MAP[j][k]==-1 || (MAP[j][i]==-1 && MAP[i][k]==-1)){
                    MAP[j][k] = -1;
                }
            }
        }
    }
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
    
    int f, t;
    for(int i=0; i<E; i++){
        cin >> f >> t;
        MAP[f][t] = 1;
        MAP[t][f] = -1;
    }
    
    floyd();

    for(int i=1; i<=V; i++){
        int count = 0;
        for(int j=1; j<=V; j++){
            if(i==j) continue;
            if(MAP[i][j] == INF) count++;
        }
        cout << count << "\n";
    }
}

