// https://www.acmicpc.net/problem/1516
// 게임 개발
// Written in C++ langs
// 2020. 06. 02.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int N;
int TIMES[501];
int INCOME[501];
int INDEGREE[501];
bool VISITED[501];
vector<vector<int>> EDGE;

void topology(){
    queue<int> que;
    
    for(int i=1; i<=N; i++){
        if(INDEGREE[i] == 0){
            que.push(i);
            VISITED[i] = true;
            INCOME[i] = 0;
        }
    }
    
    while(!que.empty()){
        int c = que.front();
        que.pop();

        for(auto e : EDGE[c]){
            INCOME[e] = max(INCOME[e], INCOME[c]+TIMES[c]);
            
            if(--INDEGREE[e] == 0 && !VISITED[e]){
                que.push(e);
                VISITED[e] = true;
            }
        }
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    EDGE.resize(N+1);
    
    int t, v;
    for(int i=1; i<=N; i++){
        cin >> t;
        TIMES[i] = t;
        while(true){
            cin >> v;
            if(v == -1) break;
            EDGE[v].push_back(i);
            INDEGREE[i]++;
        }
    }
    
    topology();
    
    for(int i=1; i<=N; i++){
        cout << INCOME[i]+TIMES[i] << " ";
    }
}

