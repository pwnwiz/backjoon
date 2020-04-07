// https://www.acmicpc.net/problem/9663
// N-Queen
// Written in C++ langs
// 2020. 04. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;
vector<pair<int,int>> QUEEN;
int COL[15] = {0,};
int COUNT = 0;
int N;

bool is_ok(int idx){
    for(int i=0; i<idx; i++){
        if(COL[i] == COL[idx] || abs(COL[idx] - COL[i]) == abs(idx-i)) return false;
    }
    return true;
}


void backtracking(int idx){
    if(idx == N){
        COUNT++;
        return;
    }
    
    for(int i=0; i<N; i++){
        COL[idx] = i;
        if(is_ok(idx)){
            backtracking(idx+1);
        }
        COL[idx] = -1;
    }
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> N;
    
    backtracking(0);
    
    cout << COUNT << "\n";
    
    return 0;
    
}

