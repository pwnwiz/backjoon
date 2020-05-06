// https://www.acmicpc.net/problem/1753
// 최단경로
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

#define INF 99999999

using namespace std;

vector<vector<pair<int,int>>> EDGES;
int N, K, S;
int DIST[200001]={0,};

void print(){
    for(int i=1; i<=N; i++){
        if(DIST[i] >= INF) cout << "INF\n";
        else cout << DIST[i] << "\n";
    }
}

void dijkstra(int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push(make_pair(0,s));
    DIST[s] = 0;
    
    while(!pq.empty()){
        int cur = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        
        if(w > DIST[cur]) continue;
        
        for(auto e : EDGES[cur]){
            int n_cur = e.second;
            int nw = w + e.first;
            
            if(nw < DIST[n_cur]){
                DIST[n_cur] = nw;
                pq.push(make_pair(nw, n_cur));
            }
        }
    }
    print();
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    cin >> S;
    
    EDGES.resize(N+1);
    
    
    int u, v, w;
    for(int i=0; i<K; i++){
        cin >> u >> v >> w;
        EDGES[u].push_back(make_pair(w,v));
    }
    
    fill(DIST, DIST+200001, INF);
    dijkstra(S);
    
    return 0;

}

