// https://www.acmicpc.net/problem/1929
// 소수 구하기
// Written in C++ langs
// 2020. 02. 04.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long NUMBER[1000001]={0,};

void eratosthenes(int until){

    for(auto i=2; i<=until; i++){
        NUMBER[i] = i;
    }
    
    int r = int(sqrt(until));
    for(auto i=2; i<=r; i++){
        if(NUMBER[i]==i){
            for(auto j=i*i; j<=until; j+=i){
                if(NUMBER[j]==j) NUMBER[j]=i;
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int from, to;
    cin >> from >> to;
    
    eratosthenes(to);
    
    for(auto i=from; i<=to; i++){
        if(NUMBER[i] == i) cout << i << "\n";
    }
    
    return 0;
}

