// https://www.acmicpc.net/problem/2750
// 수 정렬하기
// Written in C++ langs
// 2020. 01. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string input;

int ARR[1001]={0,};

int main(){
    int count;
    scanf("%d", &count);
    
    for(int i=1; i<=count; i++)
        scanf("%d", &ARR[i]);
    
    sort(ARR+1, ARR+count+1);
    
    for(int i=1; i<=count; i++)
        printf("%d\n", ARR[i]);
}

