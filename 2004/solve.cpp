// https://www.acmicpc.net/problem/2004
// 조합 0의 개수
// Written in C++ langs
// 2020. 10. 15.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

long long get5(long long n){
    long long result = 0;
    
    for(long long i=5; n/i; i*=5){
        result += n/i;
    }
    return result;
}

long long get2(long long n){
    long long result = 0;
    
    for(long long i=2; n/i; i*=2){
        result += n/i;
    }
    return result;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    long long n, m;
    
    cin >> n >> m;
    
    long long two = get2(n) - (get2(m)+get2(n-m));
    long long five = get5(n) - (get5(m)+get5(n-m));
    
    cout << min(two,five) << "\n";
}

