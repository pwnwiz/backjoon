// https://www.acmicpc.net/problem/10451
// 순열 사이클
// Written in C++ langs
// 2020. 02. 05.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int GRAPH[1001][1001]={0,};
int VISIT[1001]={0,};
int CYCLE=0;

void addEdge(int x, int y){
    GRAPH[x][y] = 1;
}

void DFS(int start, int total, int parent){
    VISIT[start] = start;
    
    for(int i=1; i<=total; i++){
        if(GRAPH[start][i] && !VISIT[i]){
            VISIT[i] = parent;
            DFS(i, total, parent);
        }
        else if(GRAPH[start][i] && VISIT[i] == parent){
            CYCLE++;
            return;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;
    
    for(int i=0; i<count; i++){
        memset(VISIT, 0, sizeof(VISIT));
        memset(GRAPH, 0, sizeof(GRAPH));
        
        int no, val;
        cin >> no;
        for(int i=1; i<=no; i++){
            cin >> val;
            addEdge(i, val);
        }
        
        for(int i=1; i<=no; i++){
            if(!VISIT[i])
                DFS(i, no, i);
        }
        
        cout << CYCLE << "\n";
        CYCLE=0;
    }
  
    return 0;
    
}
