// https://www.acmicpc.net/problem/11055
// 가장 큰 증가 부분 수열
// Written in C++ langs
// 2020. 01. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int DP[1001]={0,};
int SEQUENCE[1001]={0,};

int main() {
    int size;
    scanf("%d", &size);
    
    for(int i=1; i<=size; i++){
        scanf("%d", &SEQUENCE[i]);
        DP[i] = SEQUENCE[i];
    }

    for(int i=2; i<=size; i++){
        for(int j=1; j<i; j++){
            if(SEQUENCE[i]>SEQUENCE[j]){
                DP[i] = max(DP[i], DP[j]+SEQUENCE[i]);
            }
        }
    }
    printf("%d\n", *max_element(begin(DP), DP+size+1));
    return 0;
}

