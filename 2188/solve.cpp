// https://www.acmicpc.net/problem/2188
// 축사 배정
// Written in C++ langs
// 2020. 06. 19.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

#define INF 987654321

using namespace std;

vector<vector<int>> EDGE;
int N, M;
int V;

// 총 용량
int CAPACITY[402][402];
int FLOW[402][402];

int networkFlow(int source, int sink){
    memset(FLOW, 0, sizeof(FLOW));
    
    int total = 0;
    
    while(true){
        vector<int> parent(V, -1);
        queue<int> que;
        
        parent[source] = source;
        que.push(source);
        
        while(!que.empty() && parent[sink] == -1){
            int here = que.front();
            que.pop();
            
            for(auto there: EDGE[here]){
                if(CAPACITY[here][there] - FLOW[here][there] > 0 && parent[there] == -1){
                    parent[there] = here;
                    que.push(there);
                }
            }
        }
        
        if(parent[sink] == -1){
            break;
        }
        
        int amount = INF;
        
        for(int p=sink; p!=source; p=parent[p]){
            amount = min(amount, CAPACITY[parent[p]][p] - FLOW[parent[p]][p]);
        }
        
        for(int p=sink; p!=source; p=parent[p]){
            FLOW[parent[p]][p] += amount;
            FLOW[p][parent[p]] -= amount;
        }
        
        total += amount;
    
    }
    
    return total;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    V = N+M+2;
    EDGE.resize(V);
    
    int source = 0;
    int sink = N+M+1;
    
    int cur;
    for(int n=1; n<=N; n++){
        cin >> cur;
        
        int preferred;
        for(int c=0; c<cur; c++){
            cin >> preferred;
            
            CAPACITY[n][N+preferred] = 1;
            EDGE[n].push_back(N+preferred);
            EDGE[N+preferred].push_back(n);
        }
        
        CAPACITY[source][n] = 1;
        EDGE[source].push_back(n);
        EDGE[n].push_back(source);
    }
    
    for(int m=1; m<=M; m++){
        CAPACITY[N+m][sink] = 1;
        EDGE[N+m].push_back(sink);
        EDGE[sink].push_back(N+m);
    }
    
    cout << networkFlow(source, sink) << "\n";
    
    return 0;
    
}

