// https://www.acmicpc.net/problem/1916
// 최소비용 구하기
// Written in C++ langs
// 2020. 05. 07.
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

#define INF 999999999999

using namespace std;

vector<vector<pair<int,int>>> EDGE;
int N, M;
int S, E;
long long DIST[1001]={0,};

void dijkstra(int s, int e){
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    DIST[s] = 0;
    pq.push(make_pair(0,s));
    
    while(!pq.empty()){
        int x = pq.top().second;
        long long w = pq.top().first;
        pq.pop();
        
        if(w > DIST[x]) continue;
        
        for(auto e : EDGE[x]){
            int y = e.second;
            long long d = e.first;
            
            if(DIST[y] > w+d){
                DIST[y] = w+d;
                pq.push(make_pair(w+d, y));
            }
        }
    }
        
    cout << DIST[e] << "\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    EDGE.resize(N+1);
    
    int x, y, w;
    for(int i=0; i<M; i++){
        cin >> x >> y >> w;
        EDGE[x].push_back(make_pair(w,y));
    }
    
    fill(DIST, DIST+N+1, INF);
    
    cin >> S >> E;
    dijkstra(S, E);
    
    return 0;
    
}

