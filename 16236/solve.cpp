// https://www.acmicpc.net/problem/16236
// 아기 상어
// Written in C++ langs
// 2020. 05. 19.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> POOL[10];
int MAP[20][20]={0,};
int N;
int BABYSHARK=2;
int T=0;
int FISH=0;
int EATEN=0;
int EAT_CNT=0;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int simulation(int x, int y){
    // 아기 물고기 위치 초기화
    MAP[x][y] = 0;
    int cnt = 0;
    queue<pair<int,int>> que;

    que.push(make_pair(x,y));
    
    bool visited[20][20]={0,};
    visited[x][y] = true;
    
    while(!que.empty()){
        queue<pair<int,int>> que2;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        cnt++;
        while(!que.empty()){
            int curx = que.front().first;
            int cury = que.front().second;
            que.pop();
            
            for(int i=0; i<4; i++){
                int nx = curx + dx[i];
                int ny = cury + dy[i];
                
                if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
                
                // 0 이거나 자기보다 크기가 크지 않은 물고기의 경우 지나갈 수 있음
                if(!visited[nx][ny] && MAP[nx][ny]<=BABYSHARK){
                    visited[nx][ny] = true;

                    if(MAP[nx][ny]>0 && MAP[nx][ny]<BABYSHARK){
                        // 물고기가 본인보다 몸집이 작은 경우에 먹을 수 있음
                        pq.push(make_pair(nx,ny));
                    } else {
                        // 물고기 찾을 때까지 수행
                        que2.push(make_pair(nx,ny));
                    }
                }
            }
        }
        
        // 먹이는 배열의 위쪽, 왼쪽 일수록 우선순위 높음
        if(!pq.empty()){
            int nx = pq.top().first;
            int ny = pq.top().second;
            EATEN++;
            EAT_CNT++;
            // 몸집 크기만큼 먹으면 몸집 증가
            if(EAT_CNT == BABYSHARK){
                BABYSHARK++;
                EAT_CNT=0;
            }
            // 모든 물고기 다 먹은 경우
            if(EATEN == FISH) return cnt;
            // 다음 위치 시뮬레이션 수행
            else return cnt + simulation(nx,ny);
        } else {
            que = que2;
        }
    }
    // 물고기 못 먹은 경우
    return 0;
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    pair<int,int> s;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> MAP[i][j];
            if(MAP[i][j]>0 && MAP[i][j]<9) FISH++;
            if(MAP[i][j]==9){
                s.first = i;
                s.second = j;
            }
        }
    }
    
    if(FISH==0) cout << "0\n";
    else cout << simulation(s.first, s.second) << "\n";
    
    return 0;
    
}

