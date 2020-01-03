// https://www.acmicpc.net/problem/10844
// 쉬운 계단 수
// Written in C++ langs
// 2020. 01. 04.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

int DP[101][10]={0,};

using namespace std;

int main(){
    int input;
    int total=0;
    scanf("%d", &input);

    for(int i=1; i<10; i++) DP[1][i] = 1;
    
    for(int i=2; i<=input; i++){
        for(int j=0; j<10; j++){
            if(j == 0) DP[i][j] = DP[i-1][j+1] % 1000000000;
            else if(j == 9) DP[i][j] = DP[i-1][j-1] % 1000000000;
            else DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1]) % 1000000000;
        }
    }
    
    for(int i=0; i<10; i++){
        total = (total +  DP[input][i]) % 1000000000;
    }
    printf("%d\n", total);
}

