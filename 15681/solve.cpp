// https://www.acmicpc.net/problem/15681
// 트리와 쿼리
// Written in C++ langs
// 2020. 08. 25.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> EDGE;
vector<int> QUERY;
vector<int> DP;
vector<int> VISITED;

int N, R, Q;

void query(int pos){
    VISITED[pos] = true;
    
    for(auto next: EDGE[pos]){
        if(VISITED[next]) continue;

        query(next);
        DP[pos] += DP[next];
    }
    
    DP[pos] += 1;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> R >> Q;
    EDGE.resize(N+1);
    VISITED.resize(N+1);
    DP.resize(N+1);
    
    int a, b;
    for(int n=0; n<N-1; n++){
        cin >> a >> b;
        EDGE[a].push_back(b);
        EDGE[b].push_back(a);
    }
    
    for(int q=0; q<Q; q++){
        cin >> a;
        QUERY.push_back(a);
    }
    
    query(R);

    for(auto q: QUERY){
        cout << DP[q] << "\n";
    }

    return 0;
}

