// https://www.acmicpc.net/problem/1162
// 도로포장
// Written in C++ langs
// 2020. 05. 06.
// Wizley

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#include <tuple>
#include <math.h>

#define INF 99999999999

using namespace std;

int N, M, K;
vector<vector<pair<int,int>>> EDGE;
long long DIST[10001][21]={0,};

void dijkstra(int s){
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
    
    DIST[s][0] = 0;
    
    pq.push({0,0,s});
    
    while(!pq.empty()){
        int x = get<2>(pq.top());
        int k = get<1>(pq.top());
        long long w = get<0>(pq.top());
        pq.pop();
        
        if(DIST[x][k] < w || k>K) continue;
        
        for(auto e : EDGE[x]){
            long long nw = w + e.first;
            int nx = e.second;
            
            if(nw < DIST[nx][k]){
                DIST[nx][k] = nw;
                pq.push({nw,k,nx});
            }
            
            if(w < DIST[nx][k+1] && k+1<=K){
                DIST[nx][k+1] = w;
                pq.push({w,k+1,nx});
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K;
    EDGE.resize(N+1);
    
    int u, v, w;
    for(int i=0; i<M; i++){
        cin >> u >> v >> w;
        EDGE[u].push_back(make_pair(w,v));
        EDGE[v].push_back(make_pair(w,u));
    }
    
    for(int i=0; i<10001; i++){
        for(int j=0; j<21; j++){
            DIST[i][j] = INF;
        }
    }
    
    dijkstra(1);
    
    long long res = INF;
    for(int i=0; i<=K; i++){
        res = min(res, DIST[N][i]);
    }
    
    cout << res << "\n";
    
    return 0;
    
}

