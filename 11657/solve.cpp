// https://www.acmicpc.net/problem/11657
// 타임머신
// Written in C++ langs
// 2020. 05. 08.
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
#include <limits.h>

#define INF LLONG_MAX

using namespace std;

vector<vector<pair<int,int>>> EDGE;
int N, M;

vector<long long> bellmanFord(){
    vector<long long> dist(N+1, INF);
    dist[1] = 0;
    bool updated = false;
    
    for(int i=0; i<N; i++){
        updated = false;
        for(int x=1; x<=N; x++){
            if(dist[x] == INF) continue;
            for(auto e : EDGE[x]){
                int w = e.first;
                int y = e.second;
                if(dist[y] > dist[x]+w){
                    dist[y] = dist[x]+w;
                    updated = true;
                }
            }
        }
        if(!updated) break;
    }
    if(updated) dist.clear();
    return dist;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    EDGE.resize(N+1);
    
    int u, v, w;
    for(int i=0; i<M; i++){
        cin >> u >> v >> w;
        EDGE[u].push_back(make_pair(w,v));
    }
    
    vector<long long> dist = bellmanFord();
    
    if(dist.empty()){
        cout << "-1\n";
    } else {
        for(int i=2; i<=N; i++){
            dist[i] == INF ? cout << "-1\n" : cout << dist[i] << "\n";
        }
    }
    
    return 0;
    
}

