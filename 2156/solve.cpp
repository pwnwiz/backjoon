// https://www.acmicpc.net/problem/2156
// 포도주 시식
// Written in C++ langs
// 2020. 01. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int DP[10001]={0,};
int WINE[10001]={0,};

int main() {
    int count;
    scanf("%d", &count);
    
    for(int i=1; i<=count; i++){
        scanf("%d", &WINE[i]);
    }

    if(count<=1){
        printf("%d\n", WINE[1]);
        exit(0);
    }
    DP[1] = WINE[1];
    DP[2] = WINE[1] + WINE[2];
    
    for(int i=3; i<=count; i++){
        DP[i] = max(DP[i-1], DP[i-2] + WINE[i]);
        DP[i] = max(DP[i], DP[i-3] + WINE[i-1] + WINE[i]);
    }
    
    printf("%d\n", DP[count]);
}

