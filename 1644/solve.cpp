// https://www.acmicpc.net/problem/1644
// 소수의 연속합
// Written in C++ langs
// 2020. 03. 23.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> PRIME;
int BEGIN=0, END=0;
int COUNT=0;

bool isPrime(int num){
    if(num == 1) return false;
    for(int i=2; i*i<=num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i=2; i<=N; i++){
        if(isPrime(i)){
            PRIME.push_back(i);
        }
    }
    
    int sum=0;
    while(END<PRIME.size()){
        sum = sum + PRIME[END];
        
        if(sum >= N){
            while(sum - PRIME[BEGIN] >= N && BEGIN<=END){
                sum = sum - PRIME[BEGIN];
                BEGIN ++;
            }
            
            if(sum == N){
                COUNT = COUNT + 1;
            }
        }
        
        END++;
    }
    
    (N==1) ? cout << "0\n" : cout << COUNT << "\n";

    return 0;
    
}

