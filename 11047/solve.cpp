// https://www.acmicpc.net/problem/11047
// 동전 0
// Written in C++ langs
// 2020. 03. 05.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int COIN[10]={0,};
int RES = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> COIN[i];
    }
    
    int remain = K;
    while(remain>0){
        RES++;
        int choice=0;
        int val = remain - COIN[choice];
        for(int i=0; i<N; i++){
            if(remain - COIN[i] >= 0){
                if(val > remain - COIN[i]){
                    choice = i;
                    val = remain - COIN[choice];
                }
            }
        }
        remain = val;

    }
    
    cout << RES << "\n";
    return 0;
    
}

