// https://www.acmicpc.net/problem/11724
// 연결 요소의 개수
// Written in C++ langs
// 2020. 02. 05.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int ARR[1001][1001]={0,};
int VISIT[1001]={0,};
int N, M;
int TOTAL=0;

void addEdge(int x, int y){
    ARR[x][y]=1;
    ARR[y][x]=1;
}

void DFS(int start){
    if(!VISIT[start]){
        VISIT[start]=1;
    }
    
    for(int i=1; i<=N; i++){
        if(!VISIT[i] && ARR[start][i]){
            DFS(i);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertex1, vertex2;
    cin >> N >> M;
    
    for(int i=0; i<M; i++){
        cin >> vertex1 >> vertex2;
        addEdge(vertex1, vertex2);
    }
    
    for(int i=1; i<=N; i++){
        if(!VISIT[i]){
            TOTAL++;
            DFS(i);
        }
    }
        
    cout << TOTAL << "\n";
    
    return 0;
    
}

