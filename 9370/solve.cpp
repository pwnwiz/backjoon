// https://www.acmicpc.net/problem/9370
// 미확인 도착지
// Written in C++ langs
// 2020. 06. 04.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int TC;
int N, M, T;
int S, G, H;
int W;

vector<int> dijkstra(vector<vector<pair<int,int>>> &edge, int s, vector<int> &dest){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    vector<int> distance(N+1);
    fill(distance.begin(), distance.end(), INT_MAX);
    
    distance[s] = 0;
    pq.push(make_pair(0, s));
    
    while(!pq.empty()){
        int w = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        
        if(distance[x] < w) continue;
        
        for(auto e : edge[x]){
            int nw = e.first;
            int nx = e.second;
            
            if(distance[nx] > w + nw){
                distance[nx] = w + nw;
                pq.push(make_pair(distance[nx], nx));
            }
        }
    }
    
    return distance;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> TC;
    
    for(int i=0; i<TC; i++){
        cin >> N >> M >> T;
        cin >> S >> G >> H;
        
        vector<int> target;
        target.push_back(G);
        target.push_back(H);
        
        vector<vector<pair<int,int>>> edge;
        edge.resize(N+1);
        vector<int> dest;
        
        int a, b, d;
        for(int m=0; m<M; m++){
            cin >> a >> b >> d;
            if((a==G && b==H) || (a==H && b==G)) W = d;
            edge[a].push_back(make_pair(d, b));
            edge[b].push_back(make_pair(d, a));
        }
        
        int x;
        for(int t=0; t<T; t++){
            cin >> x;
            dest.push_back(x);
        }
        
        vector<int> dest_from_s;
        dest_from_s = dijkstra(edge, S, dest);
        
        vector<int> result;
        for(auto endpoint : dest){
            vector<int> dest_end;
            dest_end = dijkstra(edge, endpoint, target);
            
            if((dest_from_s[endpoint] == dest_from_s[G]+dest_end[H]+W) ||
               dest_from_s[endpoint] == dest_from_s[H]+dest_end[G]+W){
                result.push_back(endpoint);
            }
        }
        
        sort(result.begin(), result.end());
        for(auto r : result){
            cout << r << " ";
        }
        cout << "\n";
    }
    
    return 0;
    
}

