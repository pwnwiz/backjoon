// https://www.acmicpc.net/problem/2193
// 이친수
// Written in C++ langs
// 2020. 01. 06.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long int DP[101]={0,};

int main(){
    int input;
    
    scanf("%d", &input);

    DP[1] = 1;
    DP[2] = 1;
    
    for(int i=3; i<=input; i++)
        DP[i] = DP[i-2] + DP[i-1];
    
    printf("%lld\n", DP[input]);
    return 0;
}

