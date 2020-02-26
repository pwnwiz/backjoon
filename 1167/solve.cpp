// https://www.acmicpc.net/problem/1167
// 트리의 지름
// Written in C++ langs
// 2020. 02. 26.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;

vector<pair<int, int>> TREE[100001];
bool VISITED[100001]={0,};
int COUNT=0;
int LENGTH=0;
int U=0;

void DFS(int x, int weight){
    VISITED[x] = true;
    
    if(LENGTH < weight){
        LENGTH = weight;
        U = x;
    }

    for(int i=0; i<TREE[x].size(); i++){
        int next = TREE[x][i].first;
        if(!VISITED[next]){
           DFS(next, weight+TREE[x][i].second);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> COUNT;
    int from_vertex;
    int to_vertex;
    int dest;
    
    for(int i=0; i<COUNT; i++){
        cin >> from_vertex >> to_vertex;
        while(to_vertex!=-1){
            cin >> dest;
            TREE[from_vertex].push_back(make_pair(to_vertex, dest));
            cin >> to_vertex;
        }
    }
    
    DFS(1, 0);
    memset(VISITED, false, sizeof(VISITED));
    DFS(U, 0);
    
    cout << LENGTH << "\n";
    
    return 0;
    
}

