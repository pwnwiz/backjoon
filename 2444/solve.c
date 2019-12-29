// https://www.acmicpc.net/problem/2444
// 별 찍기 -7
// Written in C langs
// 2019. 12. 29.
// Wizley

#include <stdio.h>

int main(){
    int input;
    scanf("%d", &input);
    
    for(int i=0; i<(input-1); i++){
        for(int j=0; j<input-i-1; j++) printf(" ");
        for(int j=0; j<2*i+1; j++) printf("*");
        printf("\n");
    }

    for(int i=(input-1); i>=0; i--){
        for(int j=0; j<(input-1)-i; j++) printf(" ");
        for(int j=0; j<2*i+1; j++) printf("*");
        printf("\n");
    }
    
}

