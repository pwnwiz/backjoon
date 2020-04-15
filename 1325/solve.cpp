// https://www.acmicpc.net/problem/1325
// 효율적인 해킹
// Written in C++ langs
// 2020. 04. 15.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int N, M;
vector<int> EDGE[10001];
vector<pair<int,int>> RESULT;
bool VISITED[10001]={0,};

bool compare(const pair<int,int> &A, const pair<int,int> &B){
    if(A.second > B.second) return true;
    else if(A.second == B.second && A.first < B.first) return true;
    return false;
}

int bfs(int idx){
    queue<int> que;
    int cnt = 0;
    
    que.push(idx);
    VISITED[idx] = true;
    
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        
        for(int i=0; i<EDGE[cur].size(); i++){
            int next = EDGE[cur][i];
            if(!VISITED[next]){
                VISITED[next] = true;
                que.push(next);
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        if(VISITED[i]) cnt++;
    }
    
    return cnt;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        EDGE[b].push_back(a);
    }
    
    for(int i=1; i<=N; i++){
        memset(VISITED, false, sizeof(VISITED));
        RESULT.push_back(make_pair(i, bfs(i)));
    }
    
    sort(RESULT.begin(), RESULT.end(), compare);
    
    int ans = RESULT[0].second;
    for(int i=0; i<RESULT.size(); i++){
        if(RESULT[i].second == ans){
            cout << RESULT[i].first << " ";
        }
    }
    cout << "\n";
    
    return 0;
    
}

