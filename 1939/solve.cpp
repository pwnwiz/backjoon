// https://www.acmicpc.net/problem/1939
// 중량제한
// Written in C++ langs
// 2020. 04. 17.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;

vector<vector<pair<int,int>>> BRIDGES(10001);

int N, M;
int FROM, TO;
bool VISITED[10001]={0,};

bool bfs(int weight){
    queue<int> que;
    VISITED[FROM] = true;
    que.push(FROM);
    
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        
        if(cur == TO) return true;
        
        for(int i=0; i<BRIDGES[cur].size(); i++){
            int next = BRIDGES[cur][i].first;
            
            if(!VISITED[next] && BRIDGES[cur][i].second >= weight){
                VISITED[next] = true;
                que.push(next);
            }
        }
    }
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    int a,b,c;
    int max_c = 0;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        BRIDGES[a].push_back(make_pair(b,c));
        BRIDGES[b].push_back(make_pair(a,c));
        max_c = max(max_c, c);
    }
    cin >> FROM >> TO;
    
    int hi = max_c+1;
    int lo = 0;
    while(lo+1 < hi){
        memset(VISITED, false, sizeof(VISITED));
        int md = (lo+hi)/2;
        if(bfs(md)) lo = md;
        else hi = md;
    }
    cout << lo << "\n";

    return 0;
}

