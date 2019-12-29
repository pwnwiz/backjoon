// https://www.acmicpc.net/problem/2443
// 별 찍기 -6
// Written in C langs
// 2019. 12. 29.
// Wizley

#include <stdio.h>

int main(){
    int input;
    scanf("%d", &input);

    for(int i=(input-1); i>=0; i--){
        for(int j=0; j<(input-1)-i; j++) printf(" ");
        for(int j=0; j<2*i+1; j++) printf("*");

        printf("\n");
    }
    
}

