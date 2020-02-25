// https://www.acmicpc.net/problem/9466
// 텀 프로젝트
// Written in C++ langs
// 2020. 02. 24.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int SIZE=0;
int GRAPH[100001]={0,};

int VISIT[100001]={0,};
int FINISHED[100001]={0,};
int COUNT=0;

void addEdge(int idx){
    int value;
    cin >> value;
    GRAPH[idx]=value;
}

void DFS(int idx){
    VISIT[idx] = 1;
    
    int next = GRAPH[idx];
    if(!VISIT[next])
        DFS(next);
    
    else if(!FINISHED[next]){
        for(int i=next; i!=idx; i=GRAPH[i]){
            COUNT++;
        }
        COUNT++;
    }
    
    FINISHED[idx] = 1;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int count;
    cin >> count;
    
    for(int i=0; i<count; i++){
        cin >> SIZE;
        memset(VISIT, 0, sizeof(VISIT));
        memset(FINISHED, 0, sizeof(FINISHED));
        
        for(int i=1; i<=SIZE; i++){
            addEdge(i);
        }
        
        for(int i=1; i<=SIZE; i++){
            if(!VISIT[i]) DFS(i);
        }
        
        cout << SIZE-COUNT << "\n";
        COUNT = 0;
    }
    
    return 0;
    
};



