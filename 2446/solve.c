// https://www.acmicpc.net/problem/2446
// 별 찍기 -9
// Written in C langs
// 2019. 12. 29.
// Wizley

#include <stdio.h>

int main(){
    int input;
    scanf("%d", &input);

    for(int i=input; i>0; i--){
        for(int j=input; j>i; j--) printf(" ");
        for(int j=0; j<i*2-1; j++) printf("*");
        printf("\n");
    }
    
    for(int i=1; i<input; i++){
        for(int j=input; j>i+1; j--) printf(" ");
        for(int j=0; j<2*i+1; j++) printf("*");
        printf("\n");
    }
    
}

