// https://www.acmicpc.net/problem/1451
// 직사각형으로 나누기
// Written in C++ langs
// 2020. 03. 10.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int ARR[101][101]={0,};
long long RESULT = 0;

long long sum(int x1, int y1, int x2, int y2){
    long long val=0;
    for(int i=y1; i<=y2; i++){
        for(int j=x1; j<=x2; j++){
            val += ARR[i][j];
        }
    }
    return val;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    long long res=0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char tmp;
            cin >> tmp;
            ARR[i][j] = tmp - '0';
        }
    }
    
    for(int i=0; i<M-2; i++){
        for(int j=i+1; j<M-1; j++){
            res  = sum(0, 0, i, N-1);
            res *= sum(i+1, 0, j, N-1);
            res *= sum(j+1, 0, M-1, N-1);
            (RESULT < res) ? RESULT = res : RESULT = RESULT;
        }
    }
    
    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            res  = sum(0, 0, M-1, i);
            res *= sum(0, i+1, M-1, j);
            res *= sum(0, j+1, M-1, N-1);
            (RESULT < res) ? RESULT = res : RESULT = RESULT;
        }
    }
    
    for(int i=M-1; i>0; i--){
        for(int j=0; j<N-1; j++){
            res  = sum(0, 0, i-1, j);
            res *= sum(0, j+1, i-1, N-1);
            res *= sum(i, 0, M-1, N-1);
            (RESULT < res) ? RESULT = res : RESULT = RESULT;
        }
    }
    
    for(int i=0; i<M-1; i++){
        for(int j=0; j<N-1; j++){
            res  = sum(0, 0, i, N-1);
            res *= sum(i+1, 0, M-1, j);
            res *= sum(i+1, j+1, M-1, N-1);
            (RESULT < res) ? RESULT = res : RESULT = RESULT;
        }
    }
     
    for(int i=N-1; i>0; i--){
        for(int j=0; j<M-1; j++){
            res  = sum(0, i, M-1, N-1);
            res *= sum(0, 0, j, i-1);
            res *= sum(j+1, 0, M-1, i-1);
            (RESULT < res) ? RESULT = res : RESULT = RESULT;
        }
    }
    
    for(int i=0; i<N-1; i++){
        for(int j=0; j<M-1; j++){
            res  = sum(0, 0, M-1, i);
            res *= sum(0, i+1, j, N-1);
            res *= sum(j+1, i+1, M-1, N-1);
            (RESULT < res) ? RESULT = res : RESULT = RESULT;
        }
    }
    
    cout << RESULT << "\n";
    
    return 0;
    
}

