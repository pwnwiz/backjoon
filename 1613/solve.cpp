// https://www.acmicpc.net/problem/1613
// 역사
// Written in C++ langs
// 2020. 04. 10.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int N, K;
int Q;
vector<pair<int,int>> QUESTIONS;
int ARR[400][400]={0,};

void floyd(){
    // 경유
    for(int i=0; i<N; i++){
        // x
        for(int j=0; j<N; j++){
            // y
            for(int k=0; k<N; k++){
                if(j==k || i==j || i==k) continue;
                if(ARR[j][i] != 0 && ARR[j][i] == ARR[i][k]){
                    ARR[j][k] = ARR[i][k];
                }
            }
        }
    }
}

void print(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << ARR[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    
    int a,b;
    for(int k=0; k<K; k++){
        cin >> a >> b;
        ARR[a-1][b-1] = -1;
        ARR[b-1][a-1] = 1;
    }

    floyd();
    
    cin >> Q;
    
    for(int q=0; q<Q; q++){
        cin >> a >> b;
        cout << ARR[a-1][b-1] << "\n";
    }
    
    return 0;
    
}

