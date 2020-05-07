// https://www.acmicpc.net/problem/16681
// 등산
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
int N, M;
int D, E;
int HEIGHT[100001]={0,};
long long DIST[100001][2]={0,};

void dijkstra(int s, int idx){
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    DIST[s][idx] = 0;
    pq.push(make_pair(0,s));

    while(!pq.empty()){
        long long w = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if(w > DIST[x][idx]) continue;

        for(auto e : EDGE[x]){
            long long d = e.first;
            int y = e.second;

            if(HEIGHT[y] <= HEIGHT[x]) continue;

            if(d + w < DIST[y][idx]){
                DIST[y][idx] = d + w;
                pq.push(make_pair(DIST[y][idx], y));
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> D >> E;
    EDGE.resize(N+1);

    for(int i=1; i<=N; i++){
        cin >> HEIGHT[i];
    }

    int x, y, w;
    for(int i=0; i<M; i++){
        cin >> x >> y >> w;
        EDGE[x].push_back(make_pair(w,y));
        EDGE[y].push_back(make_pair(w,x));
    }

    for(int i=0; i<100001; i++){
        for(int j=0; j<2; j++){
            DIST[i][j] = INF;
        }
    }

    dijkstra(1, 0);
    dijkstra(N, 1);

    long long res = LLONG_MIN;
    for(int i=1; i<=N; i++){
        if(DIST[i][0]>=INF || DIST[i][1]>=INF) continue;
        long long td = (DIST[i][0] + DIST[i][1]) * D;
        res = max(res, HEIGHT[i]*E - td);
    }

    if(res == LLONG_MIN){
        cout << "Impossible\n";
    } else {
        cout << res << "\n";
    }
    
    return 0;

}

