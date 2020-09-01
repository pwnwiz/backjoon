// https://www.acmicpc.net/problem/1010
// 다리 놓기
// Written in C++ langs
// 2020. 09. 01.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;

double combination(int n, int r){
    if(n == r) return 1;
    if(r == 1) return n;
    return combination(n-1, r) + combination(n-1, r-1);
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

