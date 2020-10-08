// https://www.acmicpc.net/problem/15558
// 점프 게임
// Written in C++ langs
// 2020. 10. 08.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

char MAP[100001][2];
bool VISITED[100001][2];
int N, K;

void bfs(){
    queue<tuple<int,int,int>> que;
    que.push({0, 0, -1});
    
    while(!que.empty()){
        int pos = get<0>(que.front());
        int side = get<1>(que.front());
        int time = get<2>(que.front());
        que.pop();

        if(pos >= N){
            cout << "1\n";
            return;
        }
        
        if(pos <= time) continue;
        
        if(pos+1<=100000 && !VISITED[pos+1][side]){
            if(MAP[pos+1][side] != '0'){
                VISITED[pos+1][side] = true;
                que.push({pos+1, side, time+1});
            }
        }
        
        if(pos-1>time && pos-1>=0 && !VISITED[pos-1][side]){
            if(MAP[pos-1][side] != '0'){
                VISITED[pos-1][side] = true;
                que.push({pos-1, side, time+1});
            }
        }
        
        if(pos+K>N){
            if(side == 1){
                VISITED[N][0] = true;
                que.push({N, 0, time+1});
            }
            else{
                VISITED[N][1] = true;
                que.push({N, 1, time+1});
            }
        } else {
            if(side == 1){
                if(MAP[pos+K][0] != '0' && !VISITED[pos+K][0]){
                    VISITED[pos+K][0] = true;
                    que.push({pos+K, 0, time+1});
                }
            } else {
                if(MAP[pos+K][1] != '0' && !VISITED[pos+K][1]){
                    VISITED[pos+K][1] = true;
                    que.push({pos+K, 1, time+1});
                }
            }
        }
    }
    
    cout << "0\n";
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    
    for(int side=0; side<2; side++){
        for(int i=0; i<N; i++){
            cin >> MAP[i][side];
        }
    }

    bfs();
    
    return 0;
    
}

