// https://www.acmicpc.net/problem/2194
// 유닛 이동시키기
// Written in C++ langs
// 2020. 08. 17.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

bool MAP[500][500];
bool VISITED[500][500];
int N, M;
int A, B, K;

pair<int,int> FROM;
pair<int,int> TO;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int RESULT = -1;

bool check(int x, int y){
    int x2 = x + A - 1;
    int y2 = y + B - 1;
    
    if(x<0 || y<0 || x2<0 || y2<0 || x>=N || x2>=N || y>=M || y2>=M) return false;
    
    for(int i=x; i<=x2; i++){
        for(int j=y; j<=y2; j++){
            if(MAP[i][j]) return false;
        }
    }
    
    return true;
}

void bfs(){
    queue<pair<int,int>> que;
    VISITED[FROM.first][FROM.second] = true;
    que.push(FROM);
    
    int cnt = 0;
    while(!que.empty()){
        queue<pair<int,int>> que2;
        
        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            
            if(x == TO.first && y == TO.second){
                RESULT = cnt;
                return;
            }
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
                
                if(!VISITED[nx][ny]){
                    if(check(nx,ny)){
                        VISITED[nx][ny] = true;
                        que2.push(make_pair(nx,ny));
                    }
                }
            }
        }
        
        que = que2;
        cnt++;
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    cin >> A >> B >> K;
    
    int x,y;
    for(int k=0; k<K; k++){
        cin >> x >> y;
        MAP[x-1][y-1] = true;
    }
    
    cin >> FROM.first >> FROM.second;
    FROM.first -= 1;
    FROM.second -= 1;
    cin >> TO.first >> TO.second;
    TO.first -= 1;
    TO.second -= 1;
    
    bfs();
    
    cout << RESULT << "\n";
    
    return 0;
}

