// https://www.acmicpc.net/problem/9095
// 1, 2, 3 더하기
// Written in C++ langs
// 2020. 01. 03.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

int DP[1001]={0,};

using namespace std;

int main(){
    int count;
    int input;
    scanf("%d", &count);
    
    for(int i=0; i<count; i++){
        scanf("%d", &input);
        DP[0] = 0;
        DP[1] = 1;
        DP[2] = 2;
        DP[3] = 4;
        for(int i=4; i<=input; i++){
            DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
        }
        printf("%d\n", DP[input]);
    }
}

