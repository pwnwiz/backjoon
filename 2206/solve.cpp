// https://www.acmicpc.net/problem/2206
// 벽 부수고 이동하기
// Written in C++ langs
// 2020. 11. 09.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;

int N, M;;
char MAP[1000][1000]={0,};
int VISITED[1000][1000][2]={0,};

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

queue<tuple<int,int,bool>> QUE;
void bfs(){
    int cnt = 0;
    QUE.push({0,0,0});
    VISITED[0][0][0] = true;
    VISITED[0][0][1] = false;

    while(!QUE.empty()){
        cnt++;
        queue<tuple<int,int,bool>> que2;
        while(!QUE.empty()){
            int x = get<0>(QUE.front());
            int y = get<1>(QUE.front());
            bool flag = get<2>(QUE.front());
            QUE.pop();

            if(x==M-1 && y==N-1){
                cout << cnt << "\n";
                return;
            }

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx<0 || ny<0 || nx>=M || ny>=N) continue;
                if(VISITED[nx][ny][flag]) continue;
                
                if(MAP[nx][ny] == '0'){
                    VISITED[nx][ny][flag] = VISITED[nx][ny][flag]+1;
                    que2.push({nx,ny,flag});
                }
                
                else if(MAP[nx][ny] == '1' && !flag){
                    VISITED[nx][ny][1] = VISITED[nx][ny][flag]+1;
                    que2.push({nx,ny,1});
                }
            }
        }
        QUE=que2;
    }

    cout << "-1\n";

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> MAP[i][j];
        }
    }

    bfs();

    return 0;


}

