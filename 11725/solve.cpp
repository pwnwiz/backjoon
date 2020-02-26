// https://www.acmicpc.net/problem/11725
// 트리의 부모 찾기
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

vector<int> TREE[100001];
bool VISITED[100001]={0,};
int PARENT[100001]={0,};
int COUNT=0;

void DFS(int x){
    VISITED[x] = true;
    
    for(int i=0; i<TREE[x].size(); i++){
        int next = TREE[x][i];
        if(!VISITED[next]){
            PARENT[next] = x;
            DFS(next);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> COUNT;
    int ver1, ver2;
    
    for(int i=1; i<COUNT; i++){
        cin >> ver1 >> ver2;
    
        TREE[ver1].push_back(ver2);
        TREE[ver2].push_back(ver1);
    }
    
    for(int i=1; i<=COUNT; i++){
        if(!VISITED[i]){
            DFS(i);
        }
    }
    
    for(int i=2; i<=COUNT; i++){
        cout << PARENT[i] << "\n";
    }
    
    return 0;
    
}

