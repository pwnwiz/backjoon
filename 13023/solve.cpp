// https://www.acmicpc.net/problem/13023
// ABCDE
// Written in C++ langs
// 2020. 09. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> EDGE;
vector<bool> VISITED;
int N, M;

int RESULT = 0;

void dfs(int cur, int cnt){
    if(cnt == 5){
        RESULT = true;
        return;
    }
    
    for(auto next : EDGE[cur]){
        if(!VISITED[next]){
            VISITED[next] = true;
            dfs(next, cnt+1);
            VISITED[next] = false;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    EDGE.resize(N);
    VISITED.resize(N);
    
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        EDGE[a].push_back(b);
        EDGE[b].push_back(a);
    }
    
    for(int i=0; i<N; i++){
        fill(VISITED.begin(), VISITED.end(), false);
        VISITED[i] = true;
        dfs(i, 1);
        
        if(RESULT){
            break;
        }
    }
    
    cout << RESULT << "\n";
    
    return 0;
    
}

