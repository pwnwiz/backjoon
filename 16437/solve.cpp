// https://www.acmicpc.net/problem/16437
// 양 구출 작전
// Written in C++ langs
// 2020. 08. 27.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<char,int>> ISLAND;
vector<vector<int>> BRIDGE;
vector<bool> VISITED;

int N;

long long dfs(int pos){
    long long total = 0;
    
    VISITED[pos] = true;

    for(auto b : BRIDGE[pos]){
        if(VISITED[b]) continue;
        
        total += dfs(b);
    }
    
    (ISLAND[pos].first == 'W') ? total -= ISLAND[pos].second : total += ISLAND[pos].second;
    
    // If wolves > sheep return 0
    if(total < 0) return 0;
    
    return total;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    ISLAND.resize(N+1);
    BRIDGE.resize(N+1);
    VISITED.resize(N+1, false);
    
    char a;
    int b, c;
    
    ISLAND[1] = make_pair('S', 0);
    
    for(int i=2; i<=N; i++){
        cin >> a >> b >> c;
        ISLAND[i] = make_pair(a,b);
        BRIDGE[i].push_back(c);
        BRIDGE[c].push_back(i);
    }
    
    cout << dfs(1) << "\n";
    return 0;
    
}

