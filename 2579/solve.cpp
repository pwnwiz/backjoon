// https://www.acmicpc.net/problem/2579
// 계단 오르기
// Written in C++ langs
// 2020. 01. 09.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int DP[100001][2]={0,};
int STAIRS[301]={0,};

int main() {
    int size;
    scanf("%d", &size);
    
    for(int i=1; i<=size; i++){
        scanf("%d", &STAIRS[i]);
    }

    DP[0][0] = 0;
    DP[0][1] = 0;
    DP[1][0] = STAIRS[1];
    DP[1][1] = STAIRS[1];

    for(int i=2; i<=size; i++){
        DP[i][0] = max(DP[i-2][0] + STAIRS[i], DP[i-2][1] + STAIRS[i]);
        DP[i][1] = DP[i-1][0] + STAIRS[i];
    }
    
    cout << max(DP[size][0], DP[size][1]) << endl;
    return 0;
}

