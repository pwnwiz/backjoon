// https://www.acmicpc.net/problem/2056
// 작업
// Written in C++ langs
// 2020. 06. 09.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

void topology(vector<vector<int>> &edge, vector<int> &times, vector<int> &indegree){
    vector<bool> visited;
    vector<int> spent;
    visited.resize(N+1);
    spent.resize(N+1);
    
    fill(spent.begin(), spent.end(), 0);
    
    queue<int> que;
    
    for(int i=1; i<=N; i++){
        if(indegree[i] == 0){
            que.push(i);
        }
    }
    
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        
        visited[cur] = true;
        spent[cur] += times[cur];
        
        for(auto e : edge[cur]){
            spent[e] = max(spent[e], spent[cur]);
            if(--indegree[e] == 0 && !visited[e]){
                que.push(e);
                visited[e] = true;
            }
        }
    }
    
    int result = 0;
    for(int i=1; i<=N; i++){
        result = max(result, spent[i]);
    }
    
    cout << result << "\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> times;
    vector<vector<int>> edge;
    vector<int> indegree;

    cin >> N;
    times.resize(N+1);
    edge.resize(N+1);
    indegree.resize(N+1);
    
    int a, b, c;
    for(int i=0; i<N; i++){
        cin >> a >> b;
        times[i+1] = a;
        
        for(int j=0; j<b; j++){
            cin >> c;
            edge[c].push_back(i+1);
            indegree[i+1]++;
        }
    }
    
    topology(edge, times, indegree);

    return 0;
    
}

