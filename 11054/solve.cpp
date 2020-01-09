// https://www.acmicpc.net/problem/11054
// 가장 긴 바이토닉 부분 수열
// Written in C++ langs
// 2020. 01. 09.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int DP_LOW[1001]={0,};
int DP_HIGH[1001]={0,};
int SEQUENCE[1001]={0,};

int main() {
    int size;
    int maxValue=0;
    scanf("%d", &size);
    
    for(int i=1; i<=size; i++){
        scanf("%d", &SEQUENCE[i]);
    }
    
    fill_n(DP_LOW, 1001, 1);
    fill_n(DP_HIGH, 1001, 1);
    
    for(int i=size-1; i>=1; i--){
        for(int j=size; j>i; j--){
            if(SEQUENCE[i]>SEQUENCE[j]){
                DP_LOW[i] = max(DP_LOW[i], DP_LOW[j]+1);
            }
        }
    }
    
    for(int i=2; i<=size; i++){
        for(int j=1; j<i; j++){
            if(SEQUENCE[i]>SEQUENCE[j]){
                DP_HIGH[i] = max(DP_HIGH[i], DP_HIGH[j]+1);
            }
        }
    }
    
    for(int i=1; i<=size; i++)
        if(DP_LOW[i]-1 + DP_HIGH[i] > maxValue) maxValue = DP_LOW[i]-1 + DP_HIGH[i];
    
    printf("%d\n", maxValue);
    return 0;
}

