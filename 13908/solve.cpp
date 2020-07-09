// https://www.acmicpc.net/problem/13908
// 비밀번호
// Written in C++ langs
// 2020. 07. 09.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;


int N, M;
bool SHOULD_USE[10];
int CNT = 0;

void backtracking(int idx, int used){
    
    if(idx == N){
        if(used == M){
            CNT++;
        }
        return;
    }
    
    for(int i=0; i<=9; i++){
        if(SHOULD_USE[i]){
            SHOULD_USE[i] = false;
            backtracking(idx+1, used+1);
            SHOULD_USE[i] = true;
        } else {
            backtracking(idx+1, used);
        }
    }
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    int input;
    for(int m=0; m<M; m++){
        cin >> input;
        SHOULD_USE[input] = true;
    }
    
    backtracking(0, 0);
    
    cout << CNT << "\n";
    
    return 0;

}

