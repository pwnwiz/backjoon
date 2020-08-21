// https://www.acmicpc.net/problem/1944
// 복제 로봇
// Written in C++ langs
// 2020. 08. 21.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

char MAP[50][50];
int N, M;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int TOTAL = 0;


priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
void prim(vector<vector<pair<int,int>>> &edge, vector<int> &visited, int s){
    visited[s] = true;
    
    for(auto e: edge[s]){
        int next = e.second;
        if(visited[next]) continue;
        pq.push(e);
    }
    
    while(!pq.empty()){
        int w = pq.top().first;
        int next = pq.top().second;
        pq.pop();
        
        if(visited[next]) continue;
        
        TOTAL += w;
        return prim(edge, visited, next);
    }

}

void connectEdge(vector<vector<pair<int,int>>> &edge, tuple<int,int,int> &origin, vector<tuple<int,int,int>> &dest){
    bool visited[50][50] = {0,};
    
    queue<pair<int,int>> q;
    visited[get<1>(origin)][get<2>(origin)] = true;
    q.push(make_pair(get<1>(origin),get<2>(origin)));
    
    int cnt = 1;
    while(!q.empty()){
        queue<pair<int,int>> q2;
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
                if(visited[nx][ny]) continue;
                if(MAP[nx][ny] != '1'){
                    if(MAP[nx][ny] == 'K' || MAP[nx][ny] == 'S'){
                        for(auto k:dest){
                            if(get<1>(k) == nx && get<2>(k) == ny){
                                edge[get<0>(origin)].push_back({cnt, get<0>(k)});
                                break;
                            }
                        }
                    }
                    q2.push(make_pair(nx,ny));
                    visited[nx][ny] = true;
                }
            }
        }
        q = q2;
        cnt++;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    vector<tuple<int,int,int>> key(M+1);
    
    int idx = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> MAP[i][j];
            
            if(MAP[i][j] == 'S') key[0] = {0,i,j};
            else if(MAP[i][j] == 'K'){
                key[idx] = {idx,i,j};
                idx++;
            }
        }
    }
    
    vector<vector<pair<int,int>>> edge(M+1);

    for(auto k: key){
        connectEdge(edge, k, key);
    }
    
    vector<int> visited(M+1);
    
    prim(edge, visited, 0);
    
    for(auto v : visited){
        if(!v){
            cout << "-1\n";
            return 0;
        }
    }
    
    cout << TOTAL << "\n";
    
    return 0;
    
}


