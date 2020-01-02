// https://www.acmicpc.net/problem/11721
// 열 개씩 끊어 출력하기
// Written in C++ langs
// 2020. 01. 02.
// Wizley

#include <iostream>
#include <string>

using namespace std;

string BUFFER;

int main(){
    cin >> BUFFER;
    for(int i=0; i<BUFFER.length(); i++){
        printf("%c", BUFFER[i]);
        if((i+1)%10==0 && i!=0) printf("\n");
    }
    printf("\n");
}

