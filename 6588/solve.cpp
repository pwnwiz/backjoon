// https://www.acmicpc.net/problem/6588
// 골드바흐의 추측
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
vector<int> PRIME;

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
    
    for(int i=3; i<=until; i++){
        if(NUMBER[i] == i) PRIME.push_back(i);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int no;
    cin >> no;
    
    eratosthenes(1000000);
    
    while(no!=0){
        for(int i=0; i<PRIME.size(); i++){
            if(NUMBER[no-PRIME[i]] == no-PRIME[i]){
                cout << no << " = " << PRIME[i] << " + " << no-PRIME[i] << "\n";
                break;
            }
        }
        cin >> no;
    }
    return 0;
}

