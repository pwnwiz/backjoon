// https://www.acmicpc.net/problem/2933
// 미네랄
// Written in C++ langs
// 2020. 11. 04.
// Wizley

#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

char MAP[101][101];
int X, Y;
vector<int> C;
int N;


int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

int visited[101][101];

void print(bool debug=false){
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            if(debug) cout << visited[i][j] << " ";
            else cout << MAP[i][j];
        }
        cout << "\n";
    }
}

void rebuild(int cnt){
    
}

bool need_to_move = true;
void dfs(vector<pair<int,int>> &cluster, int row, int col){
    if(row == X-1){
        need_to_move = false;
        return;
    }
    
    for(int i=0; i<4; i++){
        int nx = row + dx[i];
        int ny = col + dy[i];
        
        if(nx<0 || nx>=X || ny<0 || ny>=Y) continue;
        if(visited[nx][ny] || MAP[nx][ny] == '.') continue;
        
        visited[nx][ny] = true;
        cluster.push_back({nx,ny});
        
        dfs(cluster,nx,ny);
    }
}

void moveCluster(vector<pair<int,int>> &cluster){
    bool flag = false;
    
    while(true){
        for(auto c: cluster){
            MAP[c.first][c.second] = '.';
        }
        
        for(auto c: cluster){
            if(c.first+1 == X || MAP[c.first+1][c.second] == 'x') flag = true;
        }
        
        for(int i=0; i<cluster.size(); i++){
            if(!flag) cluster[i].first += 1;
            int row = cluster[i].first;
            int col = cluster[i].second;

            MAP[row][col] = 'x';
        }
        if(flag) break;
    }
}

void checkCluster(int row, int col){
    for(int k=0; k<4; k++){
        int nx = row + dx[k];
        int ny = col + dy[k];
        
        memset(visited, 0, sizeof(visited));
        
        if(nx<0 || ny<0 || nx>=X || ny>=Y) continue;
        if(visited[nx][ny] || MAP[nx][ny] == '.') continue;
        
        vector<pair<int,int>> cluster;
        need_to_move = true;
        
        cluster.push_back({nx,ny});
        visited[nx][ny] = true;
        dfs(cluster, nx, ny);
        
        if(!need_to_move) continue;
        
        moveCluster(cluster);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    cin >> X >> Y;
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            cin >> MAP[i][j];
        }
    }
    
    cin >> N;
    C.resize(N);
    
    for(int i=0; i<N; i++){
        cin >> C[i];
    }
    
    bool left = true;
    for(int i=0; i<C.size(); i++){
        int row = X-C[i];
        int col = 0;
        
        bool flag = false;
        if(left){
            for(col=0; col<Y; col++){
                if(MAP[row][col] == 'x'){
                    MAP[row][col] = '.';
                    flag = true;
                    break;
                }
            }
        } else {
            for(col=Y-1; col>=0; col--){
                if(MAP[row][col] == 'x'){
                    MAP[row][col] = '.';
                    flag = true;
                    break;
                }
            }
        }
        left = !left;
        if(!flag) continue;
        
        checkCluster(row, col);
    }

    print();
    return 0;
}

