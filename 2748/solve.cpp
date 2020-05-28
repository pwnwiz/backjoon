// https://www.acmicpc.net/problem/2748
// 피보나치 수 2
// Written in C++ langs
// 2020. 05. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

long long FIBON[100] = {0,};
int N;

long long fibonacci(int n){
    for(int i=2; i<=n; i++){
        FIBON[i] = FIBON[i-2] + FIBON[i-1];
    }
    return FIBON[n];
}

long long fibonacci2(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    
    return fibonacci2(n-1) + fibonacci2(n-2);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    FIBON[0] = 0;
    FIBON[1] = 1;
    
    cout << fibonacci(N) << "\n";
    
    return 0;
    
}

