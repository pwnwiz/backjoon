// https://www.acmicpc.net/problem/1699
// 제곱수의 합
// Written in C++ langs
// 2020. 01. 09.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int DP[100001]={0,};

int main() {
    int input;
    scanf("%d", &input);

    DP[1] = 1;
    
    for(int i=2; i<=input; i++){
        for(int j=1; j*j<=i; j++){
            if(DP[i] > DP[i-j*j]+1 || DP[i]==0)
                DP[i] = DP[i-j*j]+1;
        }
    }
    printf("%d\n", DP[input]);
}


