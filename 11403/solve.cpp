// https://www.acmicpc.net/problem/11403
// 경로 찾기
// Written in C++ langs
// 2020. 04. 06.
// Wizley

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int G[100][100]={0,};
bool VISITED[100]={0,};

void dfs(int idx){
    for(int i=0; i<N; i++){
        if(G[idx][i] && !VISITED[i]){
            VISITED[i] = true;
            dfs(i);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> G[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        memset(VISITED, false, sizeof(VISITED));
        dfs(i);
        
        for(int j=0; j<N; j++){
            if(VISITED[j]){
                G[i][j] = 1;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << G[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    
    return 0;
    
}

