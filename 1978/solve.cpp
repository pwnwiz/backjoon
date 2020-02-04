// https://www.acmicpc.net/problem/1978
// 소수 찾기
// Written in C++ langs
// 2020. 02. 04.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int NUMBER[1001]={0,};

void eratosthenes(){

    for(int i=2; i<1001; i++){
        NUMBER[i] = i;
    }
    
    int r = int(sqrt(1001));
    for(int i=2; i<=r; i++){
        if(NUMBER[i]==i){
            for(int j=i*i; j<1001; j+=i){
                if(NUMBER[j]==j) NUMBER[j]=i;
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int count;
    int no;
    int total=0;
    cin >> count;
    
    eratosthenes();
    
    for(int i=0; i<count; i++){
        cin >> no;
        if(NUMBER[no] == no) total ++;
    }
    
    cout << total << "\n";
    return 0;
}

