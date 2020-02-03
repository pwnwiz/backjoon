// https://www.acmicpc.net/problem/1260
// DFS와 BFS
// Written in C++ langs
// 2020. 02. 03.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int MATRIX[1001][1001]={0,};
int DFS_VISIT[1001]={0,};
int BFS_VISIT[1001]={0,};


void addEdge(int edge1, int edge2){
    MATRIX[edge1][edge2] = 1;
    MATRIX[edge2][edge1] = 1;
}

void DFS(int start, int size){
    DFS_VISIT[start] = true;
    cout << start;
    for(int i=1; i<=size; i++){
        if(!DFS_VISIT[i] && MATRIX[start][i]){
            cout << " ";
            DFS(i, size);
        }
    }
}

void BFS(int start, int size){
    queue<int> Q;
    
    Q.push(start);
    BFS_VISIT[start] = true;
    
    while(!Q.empty()){
        start = Q.front();
        cout << start;
        if(!Q.empty()) cout << " ";
        Q.pop();
        
        for(int i=1; i<=size; i++){
            if(!BFS_VISIT[i] && MATRIX[start][i]){
                Q.push(i);
                BFS_VISIT[i] = true;
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;
    
    int edge1, edge2;
    for(int i=0; i<M; i++){
        cin >> edge1 >> edge2;
        addEdge(edge1, edge2);
    }

    DFS(V, N);
    cout << "\n";
    BFS(V, N);
    cout << "\n";
    
    return 0;

}

