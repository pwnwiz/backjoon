// https://www.acmicpc.net/problem/15552
// 빠른 A+B
// Written in C++ langs
// 2020. 01. 05.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int input;
    scanf("%d", &input);
    
    for(int i=0; i<input; i++){
        int A, B;
        scanf("%d %d", &A, &B);
        printf("%d\n", A+B);
    }
    
}

