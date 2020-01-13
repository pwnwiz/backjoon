// https://www.acmicpc.net/problem/2133
// 타일 채우기
// Written in C++ langs
// 2020. 01. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int DP[31]={0,};

int main() {
    int size;
    scanf("%d", &size);
    
    DP[0] = 1;
    DP[1] = 0;
    DP[2] = 3;
    
    for(int i=3; i<=size; i++){
        DP[i] = DP[i-2]*3;
        for(int j=4; j<=i; j+=2)
            DP[i] += DP[i-j]*2;
    }
    printf("%d\n", DP[size]);
    return 0;
}


