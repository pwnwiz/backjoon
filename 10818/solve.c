// https://www.acmicpc.net/problem/10818
// 최소, 최대
// Written in C++ langs
// 2020. 01. 02.
// Wizley

#include <iostream>
#include <string>

using namespace std;

int main(){
    int arr[1000001];
    int input;
    int min = 10000001;
    int max = -1000001;
    
    scanf("%d", &input);
    for(int i=0; i<input; i++){
        scanf("%d", &arr[i]);
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }
    printf("%d %d\n", min, max);
}

