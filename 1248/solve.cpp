// https://www.acmicpc.net/problem/1248
// 맞춰봐
// Written in C++ langs
// 2020. 10. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char EXP[10][10];
int USED[10];
int N;

bool checkExp(int idx){
    int sum = 0;
    
    for(int i=idx; i>=0; i--){
        sum += USED[i];
        switch(EXP[i][idx]){
            case '0':
                if(sum != 0) return false;
                break;
            case '+':
                if(sum <= 0) return false;
                break;
            case '-':
                if(sum >= 0) return false;
                break;
        }
    }
    return true;
}

void backtracking(int pos){
    if(pos == N){
        for(int i=0; i<N; i++){
            cout << USED[i] << " ";
        }
        cout << "\n";
        exit(0);
    }
    
    for(int i=-10; i<=10; i++){
        USED[pos] = i;
        if(checkExp(pos)){
            backtracking(pos+1);
        }
        USED[pos] = 0;
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            cin >> EXP[i][j];
        }
    }
    
    backtracking(0);

    return 0;
}


