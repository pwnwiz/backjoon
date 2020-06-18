// https://www.acmicpc.net/problem/11376
// 열혈강호2
// Written in C++ langs
// 2020. 06. 18.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

#define INF 987654321

using namespace std;

int N, M;
int V;

// u -> v로 보낼 수 있는 최대 용량
int CAPACITY[2002][2002];

// u -> v로 흘러가는 유량 ( 반대면 음수 값을 가짐 )
int FLOW[2002][2002];

vector<vector<int>> EDGE;

// source는 시작점, sink는 도착점
int networkFlow(int source, int sink){
    memset(FLOW, 0, sizeof(FLOW));
    
    int totalFlow = 0;
    
    while(true){
        vector<int> parent(V, -1);
        queue<int> que;
        
        // 흘러가는 경로를 저장하기 위함
        parent[source] = source;
        que.push(source);
        
        while(!que.empty() && parent[sink] == -1){
            int here = que.front();
            que.pop();
            
            // EDGE를 통해 직접 연결된 애들만 순회하게 되면 시간복잡도가 줄어듬
            for(int t=0; t<EDGE[here].size(); t++){
                int there = EDGE[here][t];
                // 잔여 용량이 0보다 큰 경우
                if(CAPACITY[here][there] - FLOW[here][there] > 0 && parent[there] == -1){
                    parent[there] = here;
                    que.push(there);
                }
            }
        }
        
        if(parent[sink] == -1) break;
        
        int amount = INF;
        
        for(int p=sink; p!=source; p=parent[p]){
            amount = min(CAPACITY[parent[p]][p] - FLOW[parent[p]][p], amount);
        }
        
        for(int p=sink; p!=source; p=parent[p]){
            FLOW[parent[p]][p] += amount;
            FLOW[p][parent[p]] -= amount;
        }
        
        totalFlow += amount;
    }
    
    return totalFlow;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    V = N+M+2;
    
    vector<vector<int>> work;
    work.resize(N+1);
    
    EDGE.resize(V);
    
    int source = 0;
    int sink = V-1;
    
    int c;
    for(int n=1; n<=N; n++){
        cin >> c;
            
        int d;
        for(int cnt=0; cnt<c; cnt++){
            cin >> d;
            EDGE[n].push_back(N+d);
            EDGE[N+d].push_back(n);
            CAPACITY[n][N+d] = 1;
        }
        
        // source에서 가는 값
        EDGE[source].push_back(n);
        EDGE[n].push_back(source);
        CAPACITY[source][n] = 2;
    }

    // sink로 가는 값
    for(int m=1; m<=M; m++){
        EDGE[N+m].push_back(sink);
        EDGE[sink].push_back(N+m);
        CAPACITY[N+m][sink] = 1;
    }
    
    cout << networkFlow(source, sink) << "\n";
    
    return 0;
    
}

