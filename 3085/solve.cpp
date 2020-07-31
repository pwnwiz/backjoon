// https://www.acmicpc.net/problem/3085
// 사탕 게임
// Written in C++ langs
// 2020. 07. 31.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char MAP[50][50];
int N;

int RESULT = 0;

void countResult(){
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char now = MAP[i][j];
            
            for(int k=0; k<4; k++){
                int cnt = 0;
                
                int nx = i;
                int ny = j;
                
                while(MAP[nx][ny] == now){
                    cnt ++;
                    nx += dx[k];
                    ny += dy[k];
                }
                RESULT= max(RESULT, cnt);
                
            }
        }
    }
    
    
}


void simulation(){
    
    // <->
    for(int i=0; i<N; i++){
        for(int j=0; j<N-1; j++){
            char a = MAP[i][j];
            char b = MAP[i][j+1];
            
            if(a!=b){
                MAP[i][j] = b;
                MAP[i][j+1] = a;
                countResult();
                MAP[i][j] = a;
                MAP[i][j+1] = b;
            }
        }
    }
    
    for(int i=0; i<N-1; i++){
        for(int j=0; j<N; j++){
            char a = MAP[i][j];
            char b = MAP[i+1][j];
            
            if(a!=b){
                MAP[i][j] = b;
                MAP[i+1][j] = a;
                countResult();
                MAP[i][j] = a;
                MAP[i+1][j] = b;
            }
        }
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> MAP[i][j];
        }
    }
    
    simulation();
    
    cout << RESULT << "\n";
    
    return 0;
    
}

