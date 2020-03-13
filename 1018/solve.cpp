// https://www.acmicpc.net/problem/1018
// 체스판 다시 칠하기
// Written in C++ langs
// 2020. 03. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct XY{
    int x;
    int y;
}XY;

int N, M;
char CHESS[51][51]={0,};
bool VISITED[51][51]={0,};
int COUNT = 999999;

int getSum(int x1, int y1, int x2, int y2){
    int count = 0;
    
    for(int i = x1; i<x2; i++){
        for(int j=y1; j<y2; j++){
            
            if((i%2) ^ (j%2)){
                if(CHESS[i][j] == CHESS[x1][y1]){
                    count++;
                }
            }
            else{
                if(CHESS[i][j] != CHESS[x1][y1]){
                    count++;
                }
            }
        }
    }
    return count;
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> CHESS[i][j];
        }
    }
    
    for(int i=0; i+8<=N; i++){
        for(int j=0; j+8<=M; j++){
            int val = getSum(i, j, i+8, j+8);
            COUNT = min(COUNT, val);
            COUNT = min(COUNT, 64-val);

        }
    }
    
    cout << COUNT << "\n";
    
    return 0;
    
}

