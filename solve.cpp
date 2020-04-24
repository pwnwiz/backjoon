// https://www.acmicpc.net/problem/2211
// 네트워크 복구
// Written in C++ langs
// 2020. 04. 24.
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
vector<vector<pair<int,int>>> NETWORK(1001);
int DISTANCE[1001]={0,};
int PARENT[1001]={0,};

void dijkstra(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    
    pq.push(make_pair(0,1));
    DISTANCE[1] = 0;
    
    while(!pq.empty()){
        int x = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        
        if(DISTANCE[x] < w) continue;
        
        for(int i=0; i<NETWORK[x].size(); i++){
            int y = NETWORK[x][i].second;
            int cur_weight = NETWORK[x][i].first + w;
            
            if(cur_weight < DISTANCE[y]){
                DISTANCE[y] = cur_weight;
                pq.push(make_pair(cur_weight, y));
                PARENT[y] = x;
            }
        }
    }
    
    cout << N-1 << "\n";
    for(int i=2; i<=N; i++){
        cout << PARENT[i] << " " << i << "\n";
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> N >> M;
    int a, b, c;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        NETWORK[a].push_back(make_pair(c,b));
        NETWORK[b].push_back(make_pair(c,a));
    }
    
    for(int i=1; i<=N; i++){
        DISTANCE[i] = INF;
    }
    
    dijkstra();
    return 0;
}

