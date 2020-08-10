// https://www.acmicpc.net/problem/1405
// 미친 로봇
// Written in C++ langs
// 2020. 08. 10.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool MAP[40][40];

int N;
int DIRECTION[4];

// 동 서 남 북
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

double result = 0.0;

void backtracking(bool map[40][40], pair<int,int> pos, int cnt, double percent){
    
    if(cnt == N){
        result += percent;
        return;
    }
    
    else {
        for(int i=0; i<4; i++){
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];
            
            if(nx<0 || ny<0 || nx>=50 || ny>=50 || !DIRECTION[i]) continue;
            if(map[nx][ny]) continue;

            map[nx][ny] = true;
            backtracking(map, make_pair(nx,ny), cnt+1, percent*(DIRECTION[i]*0.01));
            map[nx][ny] = false;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<4; i++){
        cin >> DIRECTION[i];
    }
    
    MAP[20][20] = true;
    backtracking(MAP, make_pair(20,20), 0, 1.0);
    
    cout << fixed;
    cout.precision(11);
    cout << result << "\n";
    
    return 0;
}

