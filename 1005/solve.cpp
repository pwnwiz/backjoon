// https://www.acmicpc.net/problem/1005
// ACM Craft
// Written in C++ langs
// 2020. 06. 05.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T;
int N, K;
int W;

void topological_sort(vector<long long> &cost, vector<vector<int>> &edge, vector<int> &indegree, int w){
    queue<int> que;
    
    vector<long long> consumed;
    consumed.resize(N+1);
    
    vector<bool> visited;
    visited.resize(N+1);
    
    for(int i=1; i<=N; i++){
        if(indegree[i] == 0) que.push(i);
        consumed[i] = 0;
    }
    
    while(!que.empty()){
        int now = que.front();
        que.pop();
        
        visited[now] = true;
        
        for(auto next : edge[now]){
            consumed[next] = max(consumed[next], cost[now]+consumed[now]);

            if(!visited[next] && --indegree[next] == 0){
                que.push(next);
                visited[next] = true;
            }
        }
    }
    
    cout << consumed[w] + cost[w] << "\n";
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    for(int t=0; t<T; t++){
        vector<long long> cost;
        vector<int> indegree;
        
        cin >> N >> K;
        cost.resize(N+1);
        indegree.resize(N+1);

        vector<vector<int>> edge;
        edge.resize(N+1);
        
        for(int c=1; c<=N; c++){
            cin >> cost[c];
        }
        
        int a, b;
        for(int k=0; k<K; k++){
            cin >> a >> b;
            edge[a].push_back(b);
            indegree[b]++;
        }
        
        cin >> W;
        
        topological_sort(cost, edge, indegree, W);
    }
    return 0;
    
}

