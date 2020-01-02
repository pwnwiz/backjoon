// https://www.acmicpc.net/problem/8393
// 합
// Written in C++ langs
// 2020. 01. 02.
// Wizley

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int input;
    int total = 0;
    cin >> input;

    for(int i=1; i<=input; i++){
        total += i;
    }
    printf("%d\n", total);
}

