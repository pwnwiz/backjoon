// https://www.acmicpc.net/problem/1010
// 다리 놓기
// Written in C++ langs
// 2021. 01. 20.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int T;

double comb[31][31];
double combination(int n, int r){
    if(n == r) return 1;
    if(r == 1) return n;
    
    if(comb[n][r]) return comb[n][r];

    comb[n][r] = combination(n-1,r-1) + combination(n-1,r);
    return comb[n][r];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    int n, m;
    while(T--){
        cin >> n >> m;
        
        cout.precision(0);
        cout << fixed;
        cout << combination(m, n) << "\n";
    }
  
    return 0;
    
}

