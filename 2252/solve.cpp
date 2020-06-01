// https://www.acmicpc.net/problem/2252
// 줄 세우기
// Written in C++ langs
// 2020. 06. 01.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N;
int M;

vector<vector<int>> EDGE;
int INDEGREE[32001];
bool VISITED[32001];
int RESULT[32001];

void topologySort(){
    queue<int> que;
    
    int idx = 1;
    for(int i=1; i<=N; i++){
        if(INDEGREE[i] == 0 && !VISITED[i]){
            que.push(i);
            VISITED[i] = true;
            
            while(!que.empty()){
                int x = que.front();
                que.pop();
                
                RESULT[idx] = x;
                idx++;
                  
                for(int e=0; e<EDGE[x].size(); e++){
                  int y = EDGE[x][e];
                  if(--INDEGREE[y] == 0 && !VISITED[y]){
                      que.push(y);
                      VISITED[y] = true;
                  }
                }
            }
        }
    }

    for(int i=1; i<=N; i++){
        cout << RESULT[i] << " ";
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    EDGE.resize(N+1);
    
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        EDGE[a].push_back(b);
        INDEGREE[b] += 1;
    }
    
    topologySort();
    
    return 0;
    
}

