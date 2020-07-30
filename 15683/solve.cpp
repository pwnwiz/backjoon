// https://www.acmicpc.net/problem/15683
// 감시
// Written in C++ langs
// 2020. 07. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int MAP[8][8];
int N, M;

int RESULT = 987654321;

vector<pair<int, pair<int,int>>> CCTV;


void simulation(int map[8][8], int idx){
    
    if(idx >= CCTV.size()){
        int cnt = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j] == 0) cnt++;
            }
        }
        RESULT = min(RESULT, cnt);
        return;
    }
    
    int type = CCTV[idx].first;
    int x = CCTV[idx].second.first;
    int y = CCTV[idx].second.second;
    
    if(type == 1){
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
    
        for(int i=0; i<4; i++){
            int map2[8][8];
            
            for(int a=0; a<8; a++){
                for(int b=0; b<8; b++){
                    map2[a][b] = map[a][b];
                }
            }
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            while(map2[nx][ny] != 6 && nx>=0 && ny>=0 && nx<N && ny<M){
                if(map2[nx][ny] == 0 || map[nx][ny] == 8) map2[nx][ny] = 8;
                nx += dx[i];
                ny += dy[i];
            }
            
            simulation(map2, idx+1);
        }
    }
    
    if(type == 2){
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        
        for(int i=0; i<2; i++){
            int map2[8][8];
            
            for(int a=0; a<8; a++){
                for(int b=0; b<8; b++){
                    map2[a][b] = map[a][b];
                }
            }
            
            for(int j=0; j<2; j++){
                int nx = x + dx[2*i+j];
                int ny = y + dy[2*i+j];
                
                while(map2[nx][ny] != 6 && nx>=0 && ny>=0 && nx<N && ny<M){
                    if(map2[nx][ny] == 0 || map[nx][ny] == 8) map2[nx][ny] = 8;
                    nx += dx[2*i+j];
                    ny += dy[2*i+j];
                }
            }
            simulation(map2, idx+1);
        }
    }
    
    if(type == 3){
        int dx[] = {0,-1,0,1};
        int dy[] = {1,0,-1,0};
        
        for(int i=0; i<4; i++){
            int map2[8][8];
            
            for(int a=0; a<8; a++){
                for(int b=0; b<8; b++){
                    map2[a][b] = map[a][b];
                }
            }
            
            for(int j=0; j<2; j++){
                int pos = i+j;
                if(pos >= 4) pos = 0;
                int nx = x + dx[pos];
                int ny = y + dy[pos];
                
                while(map2[nx][ny] != 6 && nx>=0 && ny>=0 && nx<N && ny<M){
                    if(map2[nx][ny] == 0 || map[nx][ny] == 8) map2[nx][ny] = 8;
                    nx += dx[pos];
                    ny += dy[pos];
                }
            }
            simulation(map2, idx+1);
        }
    }
    
    if(type == 4){
        int dx[] = {0,-1,0,1};
        int dy[] = {1,0,-1,0};
        
        for(int i=0; i<4; i++){
            int map2[8][8];
            
            for(int a=0; a<8; a++){
                for(int b=0; b<8; b++){
                    map2[a][b] = map[a][b];
                }
            }
            
            for(int j=0; j<3; j++){
                int pos = i+j;
                if(pos >= 4) pos -= 4;
                int nx = x + dx[pos];
                int ny = y + dy[pos];
                
                while(map2[nx][ny] != 6 && nx>=0 && ny>=0 && nx<N && ny<M){
                    if(map2[nx][ny] == 0 || map[nx][ny] == 8) map2[nx][ny] = 8;
                    nx += dx[pos];
                    ny += dy[pos];
                }
            }
            simulation(map2, idx+1);
        }
    }

    if(type == 5){
        int dx[] = {0,-1,0,1};
        int dy[] = {1,0,-1,0};
        
        int map2[8][8];
        
        for(int a=0; a<8; a++){
            for(int b=0; b<8; b++){
                map2[a][b] = map[a][b];
            }
        }
    
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            while(map2[nx][ny] != 6 && nx>=0 && ny>=0 && nx<N && ny<M){
                if(map2[nx][ny] == 0 || map[nx][ny] == 8) map2[nx][ny] = 8;
                nx += dx[i];
                ny += dy[i];
            }
        }
        simulation(map2, idx+1);
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
            
            if(MAP[i][j]>=1 && MAP[i][j]<=5){
                CCTV.push_back(make_pair(MAP[i][j], make_pair(i,j)));
            }
        }
    }
    
    simulation(MAP, 0);
    
    cout << RESULT << "\n";
    
    return 0;
    
}

