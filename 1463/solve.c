// https://www.acmicpc.net/problem/1463
// 1로 만들기
// Written in C++ langs
// 2020. 01. 03.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int DP[1000001];

int main(){
    int input;
    scanf("%d", &input);
    
    DP[1] = 0;
    for(int i=2; i<=input; i++){
        DP[i] = DP[i-1]+1;
        if(i % 3 == 0) DP[i] = min(DP[i/3]+1, DP[i]);
        if(i % 2 == 0) DP[i] = min(DP[i/2]+1, DP[i]);
    }
    
    printf("%d\n", DP[input]);
}

