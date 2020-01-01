// https://www.acmicpc.net/problem/17608
// 막대기
// Written in C langs
// 2020. 01. 01.
// Wizley

#include <stdio.h>

int BLOCK[100001]={0,};

int main(){
    int input, val, maxVal=0, count=0;

    scanf("%d", &input);
    
    for(int i=0; i<input; i++){
        scanf("%d", &val);
        BLOCK[i] = val;
    }
    
    for(int i=(input-1); i>=0; i--){
        if(BLOCK[i]>maxVal){
            count++;
            maxVal = BLOCK[i];
        }
    }
    
    printf("%d\n", count);
}

