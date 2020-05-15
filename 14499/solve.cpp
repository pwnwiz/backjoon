// https://www.acmicpc.net/problem/14499
// 주사위 굴리기
// Written in C++ langs
// 2020. 05. 15.
// Wizley

#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int N, M, X, Y, K;
vector<int> COMMAND;
int MAP[21][21]={0,};
int DICE[6] = {0,};

void roll(int direction){
    int newDice[6] = {0,};
    switch(direction){
        case 1:
            // 동
            newDice[0] = DICE[3];
            newDice[1] = DICE[1];
            newDice[2] = DICE[0];
            newDice[3] = DICE[5];
            newDice[4] = DICE[4];
            newDice[5] = DICE[2];
            break;
        case 2:
            // 서
            newDice[0] = DICE[2];
            newDice[1] = DICE[1];
            newDice[2] = DICE[5];
            newDice[3] = DICE[0];
            newDice[4] = DICE[4];
            newDice[5] = DICE[3];
            break;
        case 3:
            // 북
            newDice[0] = DICE[4];
            newDice[1] = DICE[0];
            newDice[2] = DICE[2];
            newDice[3] = DICE[3];
            newDice[4] = DICE[5];
            newDice[5] = DICE[1];
            break;
        case 4:
            // 남
            newDice[0] = DICE[1];
            newDice[1] = DICE[5];
            newDice[2] = DICE[2];
            newDice[3] = DICE[3];
            newDice[4] = DICE[0];
            newDice[5] = DICE[4];
            break;
    }
    for(int i=0; i<6; i++){
        DICE[i] = newDice[i];
    }
}
 
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};

void simulation(){
    int nx = X;
    int ny = Y;
    
    for(int i=0; i<COMMAND.size(); i++){
        int direct = COMMAND[i];
        nx += dx[direct];
        ny += dy[direct];

        // 동서남북 확인해서 MAP밖으로 나가는지 확인
        // OOB일 경우 continue;
        if(nx<0 || ny<0 || nx>=N || ny>=M){
            nx += -dx[direct];
            ny += -dy[direct];
            continue;
        }

        // 주사위 상태 변경
        roll(direct);
        
        // 바닥칸 및 맵 상태 변경
        // MAP이 0이면 바닥->MAP
        // 그 외, MAP->바닥 , MAP->0
        int floor = MAP[nx][ny];
        
        if(floor == 0){
            MAP[nx][ny] = DICE[5];
        } else {
            DICE[5] = MAP[nx][ny];
            MAP[nx][ny] = 0;
        }
        
        // 윗 칸 출력
        int up = DICE[0];
        cout << up << "\n";
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> X >> Y >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
        }
    }
    
    int c;
    for(int i=0; i<K; i++){
        cin >> c;
        COMMAND.push_back(c);
    }
    
    simulation();
    
    return 0;
    
}

