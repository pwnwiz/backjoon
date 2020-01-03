// https://www.acmicpc.net/problem/11726
// 2×n 타일링
// Written in C++ langs
// 2020. 01. 03.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

int DP[1000001]={0,};

using namespace std;

int main(){
    int input;
    scanf("%d", &input);
    
    DP[0] = 1;
    DP[1] = 1;
    for(int i=2; i<=input; i++){
        DP[i] = (DP[i-1] + DP[i-2]) % 10007;
    }
    printf("%d\n", DP[input]);
    
}

