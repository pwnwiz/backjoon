// https://www.acmicpc.net/problem/1051
// 숫자 정사각형
// Written in C++ langs
// 2020. 07. 31.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int MINL = 0;
char MAP[50][50];

int RESULT = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    MINL = min(N, M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
        }
    }
    
    for(int length=0; length<MINL; length++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(i+length>=N || j+length>=M) continue;
                
                if(MAP[i][j] == MAP[i+length][j] &&
                   MAP[i][j+length] == MAP[i+length][j+length] && MAP[i][j] == MAP[i][j+length]){
                    
                    RESULT = max(RESULT, (length+1) * (length+1));
                }
            }
        }
    }
    
    cout << RESULT << "\n";
    
    return 0;
    
}

