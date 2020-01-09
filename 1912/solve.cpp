// https://www.acmicpc.net/problem/1912
// 연속합
// Written in C++ langs
// 2020. 01. 09.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int DP[100001]={0,};
int SEQUENCE[100001]={0,};

int main() {
    int size;
    int sum=0;
    scanf("%d", &size);
    
    for(int i=1; i<=size; i++){
        scanf("%d", &SEQUENCE[i]);
    }

    DP[1] = SEQUENCE[1];
    sum = DP[1];
    
    for(int i=2; i<=size; i++){
        DP[i] = max(DP[i-1] + SEQUENCE[i], SEQUENCE[i]);
        sum = max(DP[i], sum);
    }

    cout << sum << endl;
    return 0;
}

