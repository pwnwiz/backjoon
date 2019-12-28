// https://www.acmicpc.net/problem/2439
// 별 찍기 -2
// Written in C langs
// 2019. 12. 28.
// Wizley

#include <stdio.h>

int main(){
    int input;
    scanf("%d", &input);
    
    for(int i=0; i<input; i++){
        for(int j=0; j<input-i-1; j++) printf(" ");
        for(int j=0; j<=i; j++) printf("*");
        printf("\n");
    }
}

