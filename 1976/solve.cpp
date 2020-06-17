// https://www.acmicpc.net/problem/1976
// 여행 가자
// Written in C++ langs
// 2020. 06. 17.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int N, M;
bool MAP[201][201];

void print(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
}

void kruskal(){
    // 경유
    for(int i=1; i<=N; i++){
        // 시작
        for(int j=1; j<=N; j++){
            // 도착
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
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> MAP[i][j];
        }
    }
    
    kruskal();
    
    int cur = 0;
    int next = 0;
    bool result = true;
    for(int i=0; i<M; i++){
        if(i==0){
            cin >> cur;
        } else {
            cin >> next;
            if(!MAP[cur][next]){
                if(cur == next) continue;
                result = false;
                break;
            }
            cur = next;
        }
    }
    
    result ? cout << "YES\n" : cout << "NO\n";

    return 0;
    
}

