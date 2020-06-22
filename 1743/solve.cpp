// https://www.acmicpc.net/problem/1743
// 음식물 피하기
// Written in C++ langs
// 2020. 06. 22.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int V;
int E;

void dfs(vector<vector<int>> &edge, vector<bool> &visited, int start){
    visited[start] = true;
    
    cout << start << "\n";
    
    for(auto next : edge[start]){
        if(!visited[next]){
            dfs(edge, visited, next);
        }
    }
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // vertex count
    // edge count;
    cin >> V >> E;
    
    vector<vector<int>> edge(V+1);
    vector<bool> visited(V+1, false);
    
    int from, to;
    for(int e=0; e<E; e++){
        cin >> from >> to;
        edge[from].push_back(to);
    }
    
    for(int vertex=1; vertex<=V; vertex++){
        if(!visited[vertex]){
            dfs(edge, visited, vertex);
        }
    }
    
    return 0;
    
}

