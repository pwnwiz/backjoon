// https://www.acmicpc.net/problem/3176
// 도로 네트워크
// Written in C++ langs
// 2020. 06. 02.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <limits.h>

using namespace std;

int N, M;
vector<vector<pair<int,int>>> EDGE;
bool VISITED[100001];
int DEPTH[100001];

// ceil(log2(100000))
// 16.609640474436812
#define height 17

int PARENT[100001][height+1];
int MAXV[100001][height+1];
int MINV[100001][height+1];

// 첫 부모에 대한 정보와 깊이를 초기화 하기 위해 사용됨
void dfs(int s, int depth){
    VISITED[s] = true;
    DEPTH[s] = depth;
    
    for(auto e : EDGE[s]){
        int n = e.first;
        int w = e.second;
        
        if(!VISITED[n]){
            dfs(n, depth+1);
            PARENT[n][0] = s;
            MAXV[n][0] = MINV[n][0] = w;
        }
    }
}

void fillParent(){
    for(int i=1; i<=height; i++){
        for(int j=1; j<=N; j++){
            PARENT[j][i] = PARENT[PARENT[j][i-1]][i-1];
            MINV[j][i] = min(MINV[j][i-1], MINV[PARENT[j][i-1]][i-1]);
            MAXV[j][i] = max(MAXV[j][i-1], MAXV[PARENT[j][i-1]][i-1]);
        }
    }
}


pair<int,int> lca(int a, int b){
    int minv = INT_MAX;
    int maxv = INT_MIN;
    
    if(DEPTH[a] > DEPTH[b]) swap(a,b);
    
    // depth가 다르면 맞춰줌
    for(int i=height; i>=0; i--){
        if(DEPTH[b]-DEPTH[a] >= (1<<i)){
            minv = min(minv, MINV[b][i]);
            maxv = max(maxv, MAXV[b][i]);
            b = PARENT[b][i];
        }
    }
    
    if(a == b){
        return make_pair(minv, maxv);
    }
    
    // 조상이 다르면 같을 때까지 거슬러 올라감
    for(int i=height; i>=0; i--){
        if(PARENT[a][i] != PARENT[b][i]){
            minv = min(minv, min(MINV[a][i], MINV[b][i]));
            maxv = max(maxv, max(MAXV[a][i], MAXV[b][i]));
            
            a = PARENT[a][i];
            b = PARENT[b][i];
        }
    }
    
    minv = min(minv, min(MINV[a][0], MINV[b][0]));
    maxv = max(maxv, max(MAXV[a][0], MAXV[b][0]));
    
    return make_pair(minv, maxv);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    EDGE.resize(N+1);

    int a, b, w;
    for(int i=0; i<N-1; i++){
        cin >> a >> b >> w;
        EDGE[a].push_back(make_pair(b,w));
        EDGE[b].push_back(make_pair(a,w));
    }
    
    dfs(1,0);
    
    fillParent();

    cin >> M;
    
    for(int m=0; m<M; m++){
        cin >> a >> b;
        pair<int,int> res = lca(a,b);
        cout << res.first << " " << res.second << "\n";
    }

    return 0;
    
}

