// https://www.acmicpc.net/problem/1707
// 이분 그래프
// Written in C++ langs
// 2020. 02. 05.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> GRAPH[20001];
int VISIT[20001]={0,};
int N, M;

enum{
    RED=1,
    BLUE=2,
    CHOICE=3
};

void addEdge(int x, int y){
    GRAPH[x].push_back(y);
    GRAPH[y].push_back(x);
}

void DFS(int start, int color){
    VISIT[start]=color;
    
    for(int i=0; i<GRAPH[start].size(); i++){
        if(!VISIT[GRAPH[start][i]])
            DFS(GRAPH[start][i], CHOICE-color);
    }
}

bool isBipartiteGraph(){
    for(int i=1; i<=N; i++){
        for(int j=0; j<GRAPH[i].size(); j++){
            if(VISIT[i] == VISIT[GRAPH[i][j]]) return false;
        }
    }
    return true;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertex1, vertex2;
    int count;
    cin >> count;

    for(int k=0; k<count; k++){
        for(int i=0; i<20001; i++){
            GRAPH[i].clear();
            memset(VISIT, 0, sizeof(VISIT));
        }
        
        cin >> N >> M;
        
        for(int i=0; i<M; i++){
            cin >> vertex1 >> vertex2;
            addEdge(vertex1, vertex2);
        }
        
        for(int i=1; i<=N; i++){
            if(!VISIT[i]){
                DFS(i, RED);
            }
        }
        
        isBipartiteGraph() ? cout << "YES\n" : cout << "NO\n";
    }
    
    return 0;
    
}


