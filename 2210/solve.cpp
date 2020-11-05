// https://www.acmicpc.net/problem/2210
// 숫자판 점프
// Written in C++ langs
// 2020. 11. 05.
// Wizley

#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<tuple>
#include<string.h>

using namespace std;

set<string> result;
char MAP[5][5];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void bfs(int x, int y){
    queue<tuple<int,int,string>> que;

    string a = "";
    a += MAP[x][y];
    que.push({x,y,a});
    
    while(!que.empty()){
        int cx = get<0>(que.front());
        int cy = get<1>(que.front());
        string text = get<2>(que.front());
        que.pop();
        
        if(text.length() == 6){
            result.insert(text);
            continue;
        }
        
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx<0 || ny<0 || nx>=5 || ny>=5) continue;
            
            que.push({nx,ny,text+MAP[nx][ny]});
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    char input;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> input;
            MAP[i][j] = input;
        }
    }
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            bfs(i, j);
        }
    }
    
    cout << result.size() << "\n";
    
    return 0;
}

