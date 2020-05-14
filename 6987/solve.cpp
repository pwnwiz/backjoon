// https://www.acmicpc.net/problem/6987
// 월드컵
// Written in C++ langs
// 2020. 05. 14.
// Wizley

#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int RES[6][3]={0,};
int TMP[6][3]={0,};

int A[] = {0,0,0,0,0,1,1,1,1,2,2,2,3,3,4};
int B[] = {1,2,3,4,5,2,3,4,5,3,4,5,4,5,5};
bool RESULT[4] = {0,};

bool match(){
    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            if(RES[i][j] != TMP[i][j]) return false;
        }
    }
    return true;
}

void backtracking(int idx, int cnt){
    if(cnt == 15){
        if(RESULT[idx]) return;
        if(match()) RESULT[idx] = true;
        return;
    }
    
    int tA = A[cnt];
    int tB = B[cnt];
    
    for(int wtl=0; wtl<3; wtl++){
        TMP[tA][wtl]++;
        TMP[tB][abs(2-wtl)]++;
        
        backtracking(idx,cnt+1);
        
        TMP[tA][wtl]--;
        TMP[tB][abs(2-wtl)]--;
    }
}

void getInput(){
    for(int j=0; j<6; j++){
        for(int k=0; k<3; k++){
            cin >> RES[j][k];
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0; i<4; i++){
        getInput();
        backtracking(i,0);
    }
    
    for(int i=0; i<4; i++){
        cout << RESULT[i] << " ";
    }
    cout << "\n";
    
    return 0;
    
}

