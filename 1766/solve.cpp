// https://www.acmicpc.net/problem/1766
// 문제집
// Written in C++ langs
// 2020. 06. 08.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

void topology_sort(vector<vector<int>> &edge, vector<int> &indegree){
    vector<bool> visited;
    priority_queue<int, vector<int>, greater<>> pq;
    
    for(int i=1; i<=N; i++){
        if(indegree[i] == 0) pq.push(i);
    }
    
    visited.resize(N+1);

    while(!pq.empty()){
        int x = pq.top();
        pq.pop();
        visited[x] = true;
        
        cout << x << " ";
        
        for(auto e : edge[x]){
            if(--indegree[e]==0 && !visited[e]){
                pq.push(e);
                visited[e] = true;
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    vector<vector<int>> edge;
    vector<int> indegree;
    
    edge.resize(N+1);
    indegree.resize(N+1);
    
    fill(indegree.begin(), indegree.end(), 0);
    
    int f, t;
    for(int m=0; m<M; m++){
        cin >> f >> t;
        edge[f].push_back(t);
        indegree[t]++;
    }
    
    topology_sort(edge, indegree);
    
    return 0;
    
}

