// https://www.acmicpc.net/problem/2438
// 별 찍기 -1
// Written in C langs
// 2019. 12. 28.
// Wizley

#include <stdio.h>

int main(){
    int input;
    scanf("%d", &input);
    
    for(int i=0; i<input; i++){
        for(int j=0; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }
}

