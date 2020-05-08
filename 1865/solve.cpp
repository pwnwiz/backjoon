// https://www.acmicpc.net/problem/1865
// 웜홀
// Written in C++ langs
// 2020. 05. 08.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>
#define INF 1000000000000000

using namespace std;

vector<vector<pair<int,int>>> EDGE;

int T;
int N, M, W;

void bellmanFord(int s){
    vector<long long> dist(N+1, INF);
    dist[s] = 0;

    bool updated = false;
    for(int i=1; i<=N; i++){
        for(int x=1; x<=N; x++){
            for(auto e : EDGE[x]){
                int w = e.first;
                int y = e.second;
                
                if(dist[y] > dist[x]+w){
                    dist[y] = dist[x]+w;
                    if (i==N) updated = true;
                }
            }
        }
    }
    updated ? cout << "YES\n" : cout << "NO\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    cin >> T;
    for(int t=0; t<T; t++){
        EDGE.clear();
        
        cin >> N >> M >> W;
        EDGE.resize(N+1);
        int u, v, z;
        for(int m=0; m<M; m++){
            cin >> u >> v >> z;
            EDGE[u].push_back(make_pair(z,v));
            EDGE[v].push_back(make_pair(z,u));
        }
        for(int w=0; w<W; w++){
            cin >> u >> v >> z;
            EDGE[u].push_back(make_pair(-z,v));
        }
        
        bellmanFord(1);
    }
    
    return 0;
    
}


