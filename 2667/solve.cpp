// https://www.acmicpc.net/problem/2667
// 단지번호붙이기
// Written in C++ langs
// 2020. 02. 03.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

char MAP[26][26];
int NO;
vector<int> RESULT;

int DFS(int X, int Y){
    int count = 1;
    MAP[X][Y]='2';
    
    int DIRECT_X[4] = {-1,0,1,0};
    int DIRECT_Y[4] = {0,-1,0,1};
    
    for(int i=0; i<4; i++){
        int NEW_X = X + DIRECT_X[i];
        int NEW_Y = Y + DIRECT_Y[i];
        
        if(NEW_X>0 && NEW_Y>0 && NEW_X<=NO && NEW_Y<=NO){
            if(MAP[NEW_X][NEW_Y]=='1') count += DFS(NEW_X, NEW_Y);
        }
    }
    
    return count;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> NO;
    
    for(int i=1; i<=NO; i++){
        for(int j=1; j<=NO; j++){
            cin >> MAP[i][j];
        }
    }
    
    for(int i=1; i<=NO; i++){
        for(int j=1; j<=NO; j++){
            if(MAP[i][j]=='1') RESULT.push_back(DFS(i,j));
        }
    }
    
    sort(RESULT.begin(), RESULT.end());
    cout << RESULT.size() << "\n";
     
    for(int i=0; i<RESULT.size(); i++){
     cout << RESULT[i] << "\n";
    }
    
    return 0;
     
}

