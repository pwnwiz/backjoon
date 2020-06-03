// https://www.acmicpc.net/problem/3830
// 교수님은 기다리지 않는다
// Written in C++ langs
// 2020. 06. 03.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>
#include <string.h>

using namespace std;

int N, M;
vector<vector<pair<int, long long>>> EDGE;
vector<pair<int,int>> Q;
long long DIFF[100001];
int PARENT[100001];
bool UNKNOWN[100001];
bool VISITED[100001];

void dfs(int s, long long w){
    DIFF[s] = w;
    
    for(auto e : EDGE[s]){
        int ns = e.first;
        long long nw = e.second;
        
        if(VISITED[ns]) continue;
        
        VISITED[ns] = true;
        dfs(ns, w+nw);
    }
}

int find(int x){
    if(PARENT[x] == x) return x;
    else return PARENT[x] = find(PARENT[x]);
}

bool Union(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x==y) return false;
    
    PARENT[y] = x;
    
    return true;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    char c;
    int a, b, d;
    
    while(true){
        cin >> N >> M;
        
        EDGE.clear();
        EDGE.resize(N+1);
        
        Q.clear();
        
        memset(DIFF, 0, sizeof(DIFF));
        memset(UNKNOWN, false, sizeof(UNKNOWN));
        memset(VISITED, false, sizeof(VISITED));

        // SET의 주체로 본인을 가지도록 함
        for(int i=1; i<=N; i++){
            PARENT[i] = i;
        }

        if(N==0 && M==0) break;
        
        for(int i=0; i<M; i++){
            cin >> c;
            if(c == '!'){
                cin >> a >> b >> d;
                
                // PARENT가 다른 경우에 edge를 추가해줌
                if(Union(a,b)){
                    EDGE[a].push_back(make_pair(b,d));
                    EDGE[b].push_back(make_pair(a,-d));
                }
                
            } else if(c == '?'){
                cin >> a >> b;
        
                Q.push_back(make_pair(a,b));
                
                // PARENT가 다르면 같은 집합에 속하지 않으니 UNKNOWN
                if(find(a) != find(b)){
                    UNKNOWN[Q.size()-1] = true;
                }
            }
        }
        
        // DFS를 한 번만 돌리기 위해서 Q를 통해 입력을 받은 것
        for(int i=1; i<=N; i++){
            if(!VISITED[i]){
                VISITED[i] = true;
                dfs(i, 0);
            }
        }

        for(int i=0; i<Q.size(); i++){
            if(UNKNOWN[i]){
                cout << "UNKNOWN\n";
            } else {
                int x = Q[i].first;
                int y = Q[i].second;
                
                // DFS를 통해 구한 값의 차이가 결국 무게의 차이
                cout << DIFF[y] - DIFF[x] << "\n";
            }
        }
        
    }
    
    return 0;
    
}

