// https://www.acmicpc.net/problem/7562
// 나이트의 이동
// Written in C++ langs
// 2020. 04. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int N;
int COUNT = 0;
int VISITED[300][300]={0,};

vector<pair<int,int>> from;
vector<pair<int,int>> to;

void bfs(int x, int y, int size){
    queue<pair<int,int>> que;
    VISITED[x][y] = true;
    que.push(make_pair(x,y));

    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    
    while(!que.empty()){
        queue<pair<int,int>> que2;
        while(!que.empty()){
            
            int cur_x = que.front().first;
            int cur_y = que.front().second;
            que.pop();

            if(cur_x == to[0].first && cur_y == to[0].second){
                return;
            }
            
            for(int i=0; i<8; i++){
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];
                
                if(nx<0 || ny<0 || nx>=size || ny>=size){
                    continue;
                }
                
                if(!VISITED[nx][ny]){
                    VISITED[nx][ny] = true;
                    que2.push(make_pair(nx,ny));
                }
            }
        }
        
        que = que2;
        COUNT++;
    }
    
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        int x, y;
        int len;
        
        cin >> len;
        
        cin >> x >> y;
        from.push_back(make_pair(x,y));
        
        cin >> x >> y;
        to.push_back(make_pair(x,y));

        bfs(from[0].first, from[0].second, len);
        
        from.clear();
        to.clear();
        
        cout << COUNT << "\n";
        
        memset(VISITED, false, sizeof(VISITED));
        COUNT = 0;
    }

    
    return 0;
    
}

