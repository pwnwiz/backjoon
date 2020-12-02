// https://www.acmicpc.net/problem/16928
// 뱀과 사다리 게임
// Written in C++ langs
// 2020. 12. 02.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> LADDER;
vector<pair<int,int>> SNAKE;

int VISITED[101];
int N, M;

void bfs(){
    queue<pair<int,int>> que;
    que.push({1,1});
    VISITED[1] = 1;
    
    while(!que.empty()){
        int cur = que.front().first;
        int cnt = que.front().second;
        que.pop();
        
        if(cur == 100){
            cout << cnt-1 << "\n";
            return;
        }
        
        for(int i=1; i<=6; i++){
            int next = cur + i;
            
            if(next>100 || (VISITED[next] && VISITED[next]<cur+1)) continue;
            
            for(int l=0; l<LADDER.size(); l++){
                if(next == LADDER[l].first){
                    next = LADDER[l].second;
                    break;
                }
            }
            
            for(int s=0; s<SNAKE.size(); s++){
                if(next == SNAKE[s].first){
                    next = SNAKE[s].second;
                    break;
                }
            }
            
            que.push({next,cnt+1});
            VISITED[next] = cnt+1;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    LADDER.resize(N);
    SNAKE.resize(M);
    
    int x, y;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        LADDER[i] = {x,y};
    }
    
    int u, v;
    for(int i=0; i<M; i++){
        cin >> u >> v;
        SNAKE[i] = {u,v};
    }
    
    bfs();

    return 0;
}

