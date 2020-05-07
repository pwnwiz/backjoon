// https://www.acmicpc.net/problem/1854
// K번째 최단경로 찾기
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
#include <limits.h>

#define INF LLONG_MAX

using namespace std;

vector<vector<pair<int,int>>> EDGE;
int N, M, K;
vector<priority_queue<int, vector<int>, less<>>> PQ;

void k_dijkstra(int s){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    PQ[s].push(0);
    pq.push(make_pair(0,s));
    
    while(!pq.empty()){
        int w = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        
        for(auto e : EDGE[x]){
            int d = e.first;
            int y = e.second;
            int td = w + d;
            
            if(PQ[y].size() < K){
                PQ[y].push(td);
                pq.push(make_pair(td,y));
            }
            
            else {
                if(PQ[y].top() > td){
                    PQ[y].pop();
                    PQ[y].push(td);
                    pq.push(make_pair(td,y));
                }
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
    PQ.resize(N+1);

    int x, y, w;
    for(int i=0; i<M; i++){
        cin >> x >> y >> w;
        EDGE[x].push_back(make_pair(w,y));
    }

    k_dijkstra(1);
    
    for(int i=1; i<=N; i++){
        if(PQ[i].size() < K){
            cout << "-1\n";
        } else {
            cout << PQ[i].top() << "\n";
        }
    }
    
    return 0;

}

