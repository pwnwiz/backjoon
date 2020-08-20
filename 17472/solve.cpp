// https://www.acmicpc.net/problem/17472
// 다리 만들기 2
// Written in C++ langs
// 2020. 08. 20.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int MAP[100][100];
int ISLAND[100][100];
int DIST[7][7];
int SET[7];
int N, M;
int RESULT = 0;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int findSet(int x){
    if(SET[x] == x) return x;
    return SET[x] = findSet(SET[x]);
}

void unionSet(int x, int y){
    x = findSet(x);
    y = findSet(y);
    
    SET[y] = x;
}

void kruskal(int island_no){
    vector<tuple<int,int,int>> edge;
    
    for(int i=1; i<=island_no; i++){
        SET[i] = i;
        for(int j=1; j<=island_no; j++){
            if(DIST[i][j] != 987654321 && DIST[i][j]>=2){
                edge.push_back({DIST[i][j], i, j});
            }
        }
    }

    sort(edge.begin(), edge.end());
    
    int count = 0;
    
    for(auto e : edge){
        
        if(count == island_no-1) break;
        
        int w = get<0>(e);
        int f = get<1>(e);
        int t = get<2>(e);
        
        if(findSet(f) != findSet(t)){
            RESULT += w;
            unionSet(f, t);
            count++;
        }
        
    }
    
    if(count != island_no-1){
        cout << "-1\n";
    } else {
        cout << RESULT << "\n";
    }
    
}

void divideIsland(int island_no, int i, int j){
    ISLAND[i][j] = island_no;
    
    queue<pair<int,int>> que;
    que.push(make_pair(i,j));
    
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int v=0; v<4; v++){
            int nx = x + dx[v];
            int ny = y + dy[v];
            
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            
            if(MAP[nx][ny] == 1 && ISLAND[nx][ny] == 0){
                ISLAND[nx][ny] = island_no;
                que.push(make_pair(nx,ny));
            }
        }
    }
}

void getBridge(int no, int i, int j, int direction, int cnt){
    if(i<0 || j<0 || i>=N || j>=M) return;
    
    if(ISLAND[i][j] != 0 && ISLAND[i][j] != no){
        if(cnt == 1) return;
        DIST[no][ISLAND[i][j]] = min(DIST[no][ISLAND[i][j]], cnt);
        return;
    }
    
    if(ISLAND[i][j] == 0){
        getBridge(no, i+dx[direction], j+dy[direction], direction, cnt+1);
    }
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
    
    int island_no = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(MAP[i][j] == 1 && ISLAND[i][j] == 0){
                divideIsland(island_no, i,j);
                island_no++;
            }
        }
    }
    
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            DIST[i][j] = 987654321;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(ISLAND[i][j] != 0){
                for(int k=0; k<4; k++){
                    getBridge(ISLAND[i][j], i+dx[k], j+dy[k], k, 0);
                }
            }
        }
    }
    
    kruskal(island_no-1);

    return 0;
    
}

