// https://www.acmicpc.net/problem/1504
// 특정한 최단 경로
// Written in C++ langs
// 2020. 04. 29.
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

vector<vector<pair<int,int>>> EDGE;
int N, E;
int V1, V2;
long long DIST[801]={0,};

using namespace std;

long long dijkstra(int s, int e){
    fill(DIST, DIST+N+1, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> PQ;
    
    DIST[s] = 0;
    PQ.push(make_pair(0,s));
    
    while(!PQ.empty()){
        long long dist = PQ.top().first;
        int cur = PQ.top().second;
        PQ.pop();
        
        if(DIST[cur] < dist) continue;
        
        for(auto e : EDGE[cur]){
            long long nd = e.first;
            int next = e.second;
            
            if(DIST[next] > dist + nd){
                DIST[next] = dist+nd;
                PQ.push(make_pair(DIST[next], next));
            }
        }
    }
    return DIST[e];
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> E;
    EDGE.resize(N+1);
    
    int x, y, w;
    for(int i=0; i<E; i++){
        cin >> x >> y >> w;
        EDGE[x].push_back(make_pair(w,y));
        EDGE[y].push_back(make_pair(w,x));
    }
    
    cin >> V1 >> V2;
    
    long long r1 = dijkstra(1, V1) + dijkstra(V1, V2) + dijkstra(V2, N);
    long long r2 = dijkstra(1, V2) + dijkstra(V2, V1) + dijkstra(V1, N);
    long long res = min(r1, r2);
    if(res>=INF) cout << "-1\n";
    else cout << res << "\n";
    
    return 0;
}

