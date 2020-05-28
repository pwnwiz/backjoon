// https://www.acmicpc.net/problem/2096
// 내려가기
// Written in C++ langs
// 2020. 05. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

int BOARD[3] = {0,};
int DP[2][3] = {0,};
int DP2[2][3] = {0,};

int N;

void dp(){
    for(int j=0; j<3; j++){
        DP[1][j] = 0;
        DP2[1][j] = 987654321;
    }
    
    for(int j=0; j<3; j++){
        if(j==0){
            DP[1][j] = max(DP[1][j], DP[0][j]+BOARD[j]);
            DP[1][j+1] = max(DP[1][j+1], DP[0][j]+BOARD[j+1]);
            
            DP2[1][j] = min(DP2[1][j], DP2[0][j]+BOARD[j]);
            DP2[1][j+1] = min(DP2[1][j+1], DP2[0][j]+BOARD[j+1]);
            
        } else if(j==1){
            DP[1][j-1] = max(DP[1][j-1], DP[0][j]+BOARD[j-1]);
            DP[1][j] = max(DP[1][j], DP[0][j]+BOARD[j]);
            DP[1][j+1] = max(DP[1][j+1], DP[0][j]+BOARD[j+1]);
            
            DP2[1][j-1] = min(DP2[1][j-1], DP2[0][j]+BOARD[j-1]);
            DP2[1][j] = min(DP2[1][j], DP2[0][j]+BOARD[j]);
            DP2[1][j+1] = min(DP2[1][j+1], DP2[0][j]+BOARD[j+1]);
            
        } else if(j==2){
            DP[1][j] = max(DP[1][j], DP[0][j]+BOARD[j]);
            DP[1][j-1] = max(DP[1][j-1], DP[0][j]+BOARD[j-1]);
            
            DP2[1][j] = min(DP2[1][j], DP2[0][j]+BOARD[j]);
            DP2[1][j-1] = min(DP2[1][j-1], DP2[0][j]+BOARD[j-1]);
        }
    }
    
    for(int j=0; j<3; j++){
        DP[0][j] = DP[1][j];
        DP2[0][j] = DP2[1][j];
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin >> BOARD[j];
            
            if(i==0){
                DP[0][j] = BOARD[j];
                DP2[0][j] = BOARD[j];
            }
        }
        
        if(i>0){
            dp();
        }
    }
    
    int max_val = -1;
    int min_val = 987654321;
    
    for(int i=0; i<3; i++){
        max_val = max(max_val, DP[0][i]);
        min_val = min(min_val, DP2[0][i]);
    }

    cout << max_val << " " << min_val << "\n";
    
    return 0;
    
}

