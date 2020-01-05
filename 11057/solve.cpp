// https://www.acmicpc.net/problem/11057
// 오르막 수
// Written in C++ langs
// 2020. 01. 05.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int DP[1001][10]={0,};

int main(){
    int input;
    int result=0;
    scanf("%d", &input);

    for(int i=0; i<10; i++) DP[1][i] = 1;

    for(int i=2; i<=input; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<=j; k++){
                DP[i][j] += (DP[i-1][k]) % 10007;
            }
        }
    }

    for(int j=0; j<10; j++){
        result = (result + DP[input][j]) % 10007;
    }
    printf("%d\n", result);
}

