// https://www.acmicpc.net/problem/2447
// 별 찍기 -10
// Written in C langs
// 2019. 12. 31.
// Wizley

#include <stdio.h>
#include <math.h>

int MAP[2500][2500]={0,};

enum {
    shouldBeBlank = 1,
    cubeSize = 3
};

int calculatePower(int n){
    int val = 1;
    for(int i=0; i<10; i++){
        val *= 3;
        if(val == n) return i+1;
    }
    return -1;
}

void drawXYwithSize(int X, int Y, int size){
    
    if(size==1){
        MAP[X][Y] = 1;
        return;
    }
    int new_size = size/cubeSize;
    
    for(int i=0; i<cubeSize; i++){
        for(int j=0; j<cubeSize; j++){
            if(!(i==shouldBeBlank && j==shouldBeBlank)){
                drawXYwithSize(X+(i*new_size), Y+(j*new_size), new_size);
            }
        }
    }
}

int main(){
    int input;
    scanf("%d", &input);

    drawXYwithSize(0, 0, input);
    for(int i=0; i<input; i++){
        for(int j=0; j<input; j++) MAP[i][j]==1 ? printf("*") : printf(" ");
        printf("\n");
    }
}

