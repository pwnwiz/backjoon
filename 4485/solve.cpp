// https://www.acmicpc.net/problem/4485
// 녹색 옷 입은 애가 젤다지?
// Written in C++ langs
// 2020. 04. 24.
// Wizley

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#include <tuple>
#include <math.h>

#define INF 99999999

using namespace std;

int N;
int CAVE[126][126]={0,};
int DIST[126][126]={0,};

void dijkstra(){
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    DIST[0][0] = CAVE[0][0];
    pq.push({DIST[0][0],0,0});
    
    while(!pq.empty()){
        int w = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();
        
        if(w > DIST[x][y]) continue;
        
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        
        for(int i=0; i<4; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            
            if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
            
            int cur_w = w + CAVE[nx][ny];
            if(DIST[nx][ny] > cur_w){
                DIST[nx][ny] = cur_w;
                pq.push({cur_w, nx, ny});
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int idx = 1;
    while(true){
        cin >> N;
        if(N == 0) break;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> CAVE[i][j];
                DIST[i][j] = INF;
            }
        }
        
        dijkstra();
        
        cout << "Problem " << idx++ << ": " << DIST[N-1][N-1] << "\n";
    }
    
}

