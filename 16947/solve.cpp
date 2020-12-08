// https://www.acmicpc.net/problem/16947
// 서울 지하철 2호선
// Written in C++ langs
// 2020. 12. 08.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <queue>

using namespace std;

vector<vector<int>> EDGE;
bool CYCLE[3001];
bool VISITED[3001];
int N;

int bfs(int start){
    bool visited[3001] = {0,};
    queue<pair<int,int>> que;
    que.push({start, 0});
    visited[start] = true;
    
    while(!que.empty()){
        int cur = que.front().first;
        int cnt = que.front().second;
        que.pop();
        
        if(CYCLE[cur]) return cnt;
        
        for(auto next: EDGE[cur]){
            if(visited[next]) continue;
            
            visited[next] = true;
            que.push({next, cnt+1});
        }
    }
    return 0;
}

void dfs(int start, int current, int count){
    if(start == current && count >= 2){
        CYCLE[current] = true;
        return;
    }
    
    VISITED[current] = true;
    
    for(auto next: EDGE[current]){
        if(!VISITED[next]) dfs(start, next, count+1);
        else if(start == next && count >= 2) dfs(start, next, count);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    EDGE.resize(N+1);
    
    int a, b;
    for(int i=0; i<N; i++){
        cin >> a >> b;
        EDGE[a].push_back(b);
        EDGE[b].push_back(a);
    }
    
    for(int i=1; i<=N; i++){
        memset(VISITED, false, sizeof(VISITED));
        dfs(i, i, 0);
    }
    
    vector<int> result;
    for(int i=1; i<=N; i++){
        if(CYCLE[i]) result.push_back(0);
        else result.push_back(bfs(i));
    }
    
    for(auto r : result){
        cout << r << " ";
    }
    cout << "\n";
    
    return 0;

}

