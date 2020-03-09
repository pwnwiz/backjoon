// https://www.acmicpc.net/problem/1476
// 날짜 계산
// Written in C++ langs
// 2020. 03. 09.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int E=1, S=1, M=1;
int COUNT=1;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int target_E, target_S, target_M;
    cin >> target_E >> target_S >> target_M;
    
    while((target_E != E) || (target_S != S) || (target_M != M)){
        E == 15 ? E=1 : E = E+1;
        S == 28 ? S=1 : S = S+1;
        M == 19 ? M=1 : M = M+1;
        COUNT++;
    }
    cout << COUNT << "\n";
    return 0;
    
}

