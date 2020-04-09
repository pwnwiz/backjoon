// https://www.acmicpc.net/problem/9328
// 열쇠
// Written in C++ langs
// 2020. 04. 09.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

queue<pair<int,int>> ENTRANCE;
vector<queue<pair<int,int>>> V_DOORS(28);

bool B_KEYS[27]={0,};

char MAP[100][100]={0,};
bool VISITED[100][100]={0,};

int T;
int R, C;
int COUNT = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void getEntry(){
    for(int i=0; i<R; i++){
        if(MAP[i][0] == '.') ENTRANCE.push(make_pair(i,0));
        else if(MAP[i][0]>='A' && MAP[i][0]<='Z') V_DOORS[MAP[i][0]-'A'].push(make_pair(i,0));
        else if(MAP[i][0]>='a' && MAP[i][0]<='z'){
            B_KEYS[MAP[i][0]-'a'] = true;
            ENTRANCE.push(make_pair(i,0));
        }
        else if(MAP[i][0] == '$'){
            COUNT++;
            ENTRANCE.push(make_pair(i,0));
        }
        
        if(MAP[i][C-1] == '.') ENTRANCE.push(make_pair(i,C-1));
        else if(MAP[i][C-1]>='A' && MAP[i][C-1]<='Z') V_DOORS[MAP[i][C-1]-'A'].push(make_pair(i,C-1));
        else if(MAP[i][C-1]>='a' && MAP[i][C-1]<='z'){
            B_KEYS[MAP[i][C-1]-'a'] = true;
            ENTRANCE.push(make_pair(i,C-1));
        }
        else if(MAP[i][C-1] == '$'){
            COUNT++;
            ENTRANCE.push(make_pair(i,C-1));
        }
        VISITED[i][0] = true;
        VISITED[i][C-1] = true;
    }
    
    for(int j=1; j<C-1; j++){
        if(MAP[0][j] == '.') ENTRANCE.push(make_pair(0, j));
        else if(MAP[0][j]>='A' && MAP[0][j]<='Z') V_DOORS[MAP[0][j]-'A'].push(make_pair(0,j));
        else if(MAP[0][j]>='a' && MAP[0][j]<='z'){
            B_KEYS[MAP[0][j]-'a'] = true;
            ENTRANCE.push(make_pair(0,j));
        }
        else if(MAP[0][j] == '$'){
            COUNT++;
            ENTRANCE.push(make_pair(0,j));
        }
        
        if(MAP[R-1][j] == '.') ENTRANCE.push(make_pair(0,j));
        else if(MAP[R-1][j]>='A' && MAP[R-1][j]<='Z') V_DOORS[MAP[R-1][j]-'A'].push(make_pair(R-1,j));
        else if(MAP[R-1][j]>='a' && MAP[R-1][j]<='z'){
            B_KEYS[MAP[R-1][j]-'a'] = true;
            ENTRANCE.push(make_pair(R-1,j));
        }
        else if(MAP[R-1][j] == '$'){
            COUNT++;
            ENTRANCE.push(make_pair(R-1,j));
        }
        
        VISITED[0][j] = true;
        VISITED[R-1][j] = true;
    }
}

void enterRoom(){
    for(int i=0; i<26; i++){
        if(B_KEYS[i]){
            while(!V_DOORS[i].empty()){
                int nx = V_DOORS[i].front().first;
                int ny = V_DOORS[i].front().second;
                V_DOORS[i].pop();
                ENTRANCE.push(make_pair(nx,ny));
            }
        }
    }
}

void searchFromEntrance(){
    enterRoom();
    
    while(!ENTRANCE.empty()){
        while(!ENTRANCE.empty()){
            int start_x = ENTRANCE.front().first;
            int start_y = ENTRANCE.front().second;
            
            ENTRANCE.pop();
            
            for(int i=0; i<4; i++){
                int nx = start_x + dx[i];
                int ny = start_y + dy[i];
                
                if(nx<0 || ny<0 || nx>=R || ny>=C) continue;
                
                if(MAP[nx][ny] != '*' && !VISITED[nx][ny]){
                    VISITED[nx][ny] = true;
                    
                    if(MAP[nx][ny] >= 'A' && MAP[nx][ny] <= 'Z'){
                        V_DOORS[MAP[nx][ny]-'A'].push(make_pair(nx,ny));
                        continue;
                    }
                    
                    else if(MAP[nx][ny] == '$'){
                        COUNT++;
                    }
                    
                    else if(MAP[nx][ny] >= 'a' && MAP[nx][ny] <= 'z'){
                        B_KEYS[MAP[nx][ny]-'a'] = true;
                    }
                    
                    ENTRANCE.push(make_pair(nx,ny));
                }
            }
        }
        enterRoom();
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    for(int t=0; t<T; t++){
        cin >> R >> C;
        string input;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cin >> MAP[i][j];
            }
        }
        cin >> input;
        if(input[0] != '0'){
            for(int k=0; k<input.length(); k++){
                B_KEYS[input[k]-'a'] = true;
            }
        }
        getEntry();
        searchFromEntrance();
        
        for(int i=0; i<V_DOORS.size(); i++){
            while(!V_DOORS[i].empty()){
                V_DOORS[i].pop();
            }
        }
        
        cout << COUNT << "\n";
    
        memset(B_KEYS, false, sizeof(B_KEYS));
        memset(VISITED, false, sizeof(VISITED));
        memset(MAP, 0, sizeof(MAP));
        COUNT = 0;
    }
    
    return 0;
    
}

