// https://www.acmicpc.net/problem/16932
// 모양 만들기
// Written in C++ langs
// 2020. 12. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
int MAP[1001][1001];
int VISITED[1001][1001];
map<int,int> MAPP;
int N, M;

int IDX = 1;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void bfs(int i, int j){
    int cnt = 0;
    
    queue<pair<int,int>> que;
    que.push({i,j});
    VISITED[i][j] = IDX;
    cnt++;
    
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(VISITED[nx][ny] || MAP[nx][ny] == 0) continue;
            
            VISITED[nx][ny] = IDX;
            que.push({nx,ny});
            cnt++;
        }
    }
    
    MAPP[IDX++] = cnt;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
        }
    }
    MAPP[0] = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!VISITED[i][j] && MAP[i][j] == 1) bfs(i,j);
        }
    }
    
    int result = 0;
    for(auto mm : MAPP){
        result = max(result, mm.second);
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(MAP[i][j] == 1) continue;
            
            set<int> sett;

            for(int k=0; k<4; k++){
                int ii = i + dx[k];
                int jj = j + dy[k];
                
                if(ii<0 || jj<0 || ii>=N || jj>=M) continue;
                if(!VISITED[ii][jj]) continue;
                
                sett.insert(VISITED[ii][jj]);
            }
            
            int c = 0;
            for(auto s : sett){
                c += MAPP[s];
            }
            result = max(result, c+1);
        }
    }
    cout << result << "\n";
    return 0;

}

