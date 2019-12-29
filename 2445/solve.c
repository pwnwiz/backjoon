// https://www.acmicpc.net/problem/2445
// 별 찍기 -8
// Written in C langs
// 2019. 12. 29.
// Wizley

#include <stdio.h>

int main(){
    int input;
    scanf("%d", &input);

    for(int i=1; i<=input; i++){
        for(int j=0; j<i; j++) printf("*");
        for(int j=input; j>i; j--) printf("  ");
        for(int j=0; j<i; j++) printf("*");
        printf("\n");
    }
    
    for(int i=(input-1); i>0; i--){
        for(int j=0; j<i; j++) printf("*");
        for(int j=0; j<(input-i); j++) printf("  ");
        for(int j=0; j<i; j++) printf("*");
        printf("\n");
    }
    
}

