// https://www.acmicpc.net/problem/1094
// 막대기
// Written in C++ langs
// 2020. 05. 11.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int B = 64;
int X;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> X;

    int cnt = 1;
    
    int M = B;
    while(B > X){
        M = M/2;
        if(B-M >= X){
            B -= M;
        } else {
            cnt++;
        }
    }
    
    cout << cnt << "\n";
    
    return 0;
    
}

