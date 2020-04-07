// https://www.acmicpc.net/problem/14502
// 연구소
// Written in C++ langs
// 2020. 04. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

enum {
    SPACE=0,
    WALL=1,
    VIRUS=2,
};

vector<pair<int,int>> V_VIRUS;
vector<pair<int,int>> V_SPACE;
vector<pair<int,int>> V_COMBINATION;
int MAP[8][8]={0,};
int X, Y;
int SAFE = 0;
int COUNT;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(){
    int MAP2[8][8] = {0,};
    
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            MAP2[i][j] = MAP[i][j];
        }
    }
    
    int VISITED[8][8] = {0,};
    queue<pair<int,int>> que;
    
    for(int i=0; i<V_VIRUS.size(); i++){
        VISITED[V_VIRUS[i].first][V_VIRUS[i].second] = true;
        que.push(V_VIRUS[i]);
    }
    
    while(!que.empty()){
        int cur_x = que.front().first;
        int cur_y = que.front().second;
        que.pop();
        
        for(int i=0; i<4; i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            
            if(nx<0 || ny<0 || nx>=X || ny>=Y){
                continue;
            }
            
            if(!VISITED[nx][ny] && MAP2[nx][ny] == SPACE){
                VISITED[nx][ny] = true;
                MAP2[nx][ny] = VIRUS;
                que.push(make_pair(nx,ny));
            }
        }
        
    }
    
    int count=0;
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            if(MAP2[i][j] == SPACE){
                count++;
            }
        }
    }
    
    COUNT = max(COUNT, count);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> X >> Y;
    
    for(int x=0; x<X; x++){
        for(int y=0; y<Y; y++){
            cin >> MAP[x][y];
            if(MAP[x][y] == VIRUS){
                V_VIRUS.push_back(make_pair(x,y));
            }
            else if(MAP[x][y] == SPACE){
                V_SPACE.push_back(make_pair(x,y));
            }
        }
    }
    sort(V_SPACE.begin(), V_SPACE.end());
    
    vector<int> v;

    for(int i=0; i<V_SPACE.size(); i++){
        if(i<3){
            v.push_back(0);
        }
        else{
            v.push_back(1);
        }
    }
    
    do {
        V_COMBINATION.clear();
        for(int i=0; i<v.size(); i++){
            if(v.at(i)==0){
                V_COMBINATION.push_back(V_SPACE[i]);
            }
        }
        
        for(int i=0; i<V_COMBINATION.size(); i++){
            MAP[V_COMBINATION[i].first][V_COMBINATION[i].second] = WALL;
        }
        
        bfs();
        
        for(int i=0; i<V_COMBINATION.size(); i++){
            MAP[V_COMBINATION[i].first][V_COMBINATION[i].second] = SPACE;
        }
        
    } while(next_permutation(v.begin(), v.end()));
    
    cout << COUNT << "\n";
    
    return 0;
    
}

