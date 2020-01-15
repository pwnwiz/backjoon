// https://www.acmicpc.net/problem/11052
// 카드 구매하기
// Written in C++ langs
// 2020. 01. 15.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string input;

int DP[10001]={0,};
int ARR[10001]={0,};

int main(){
    int N;
    scanf("%d", &N);
    
    for(int i=1; i<=N; i++){
        scanf("%d", &ARR[i]);
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            DP[i] = max(DP[i], ARR[j]+DP[i-j]);
        }
    }
    printf("%d\n", DP[N]);
}

