// https://www.acmicpc.net/problem/14890
// 경사로
// Written in C++ langs
// 2020. 05. 22.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int MAP[101][101]={0,};
int RES = 0;

void checkX(int x){
    int cnt = 1;
    for(int j=0; j<N-1; j++){
        int v = MAP[x][j+1] - MAP[x][j];
        if(v == 0) cnt++;
        else if(v == 1 && cnt>=L) cnt=1;
        else if(v == -1 && cnt>=0) cnt = -L+1;
        else return;
    }
    if(cnt>=0) RES++;
}

void checkY(int y){
    int cnt = 1;
    for(int j=0; j<N-1; j++){
        int v = MAP[j+1][y] - MAP[j][y];
        if(v == 0) cnt++;
        else if(v == 1 && cnt>=L) cnt=1;
        else if(v == -1 && cnt>=0) cnt = -L+1;
        else return;
    }
    if(cnt>=0)RES++;
}


void simulation(){
    for(int i=0; i<N; i++){
        checkX(i);
        checkY(i);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> L;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> MAP[i][j];
        }
    }
    
    simulation();
    cout << RES << "\n";
    
    return 0;
    
}

