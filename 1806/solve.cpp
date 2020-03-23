// https://www.acmicpc.net/problem/1806
// 부분합
// Written in C++ langs
// 2020. 03. 23.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N, S;
int ARR[100001]={0,};
int BEGIN=0, END = 0;
int MIN = 999999;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> S;
    
    for(int i=0; i<N; i++){
        cin >> ARR[i];
    }
    
    int sum = 0;
    while(END<=N){
        sum = sum + ARR[END];
        
        if(sum >= S){
            while(sum - ARR[BEGIN] >= S && BEGIN <= END){
                sum = sum - ARR[BEGIN];
                BEGIN = BEGIN + 1;
            }
            MIN = min(MIN, END-BEGIN);
        }
        END++;
    }
    
    if(MIN>=999999){
        cout << "0\n";
    }
    else{
        cout << MIN+1 << "\n";
    }
    
    
    return 0;
    
}

