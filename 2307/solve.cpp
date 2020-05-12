// https://www.acmicpc.net/problem/2307
// 도로검문
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

#define INF 99999999

using namespace std;

int N, M;
vector<vector<pair<int,int>>> EDGE;
int DIST[1001]={0,};
int PARENT[1001]={0,};
int SHORTEST = 0;
int LONGEST = 0;

void dijkstra(){
    DIST[1] = 0;
    PARENT[1] = 1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push(make_pair(0,1));
    
    while(!pq.empty()){
        int w = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(w > DIST[cur]) continue;
        
        for(auto e : EDGE[cur]){
            int nw = e.first;
            int next = e.second;
            
            if(DIST[next] > w + nw){
                DIST[next] = w + nw;
                pq.push(make_pair(DIST[next], next));
                PARENT[next] = cur;
            }
        }
    }
    
    SHORTEST = DIST[N];
}

int dijkstra_2(int a, int b){
    DIST[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push(make_pair(0,1));
    
    while(!pq.empty()){
        int w = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(w > DIST[cur]) continue;
        
        for(auto e : EDGE[cur]){
            int nw = e.first;
            int next = e.second;
            
            if((cur==a && next==b) || (cur==b && next==a)) continue;
            
            if(DIST[next] > w + nw){
                DIST[next] = w + nw;
                pq.push(make_pair(DIST[next], next));
            }
        }
    }
    
    return DIST[N];
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    EDGE.resize(N+1);
    
    int w, x, y;
    for(int i=0; i<M; i++){
        cin >> x >> y >> w;
        EDGE[x].push_back(make_pair(w,y));
        EDGE[y].push_back(make_pair(w,x));
    }
    
    fill(DIST, DIST+N+1, INF);
    dijkstra();
    
    for(int i=N; i!=PARENT[i]; i=PARENT[i]){
        fill(DIST, DIST+N+1, INF);
        LONGEST = max(LONGEST, dijkstra_2(i, PARENT[i]));
    }
    
    if(LONGEST >= INF) cout << "-1\n";
    else cout << LONGEST - SHORTEST << "\n";
    
    return 0;
    
}

