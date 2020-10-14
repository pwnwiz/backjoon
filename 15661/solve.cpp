// https://www.acmicpc.net/problem/15661
// 링크와 스타트
// Written in C++ langs
// 2020. 10. 14.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>

int MAP[21][21];
int N;

using namespace std;

int MINV = 987654321;
char TEAM[21];
void backtracing(int pos){
    
    if(pos == N){
        int A = 0;
        int B = 0;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(TEAM[i] == TEAM[j]){
                    if(TEAM[i] == 'A') A+= MAP[i][j];
                    else B += MAP[i][j];
                }
            }
        }
        if(A==0 || B==0) return;
        MINV = min(MINV, abs(A-B));
        return;
    }
    
    TEAM[pos] = 'A';
    backtracing(pos+1);
    
    TEAM[pos] = 'B';
    backtracing(pos+1);
};

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
    
    backtracing(0);
    
    cout << MINV << "\n";
}

