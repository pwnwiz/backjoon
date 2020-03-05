// https://www.acmicpc.net/problem/2875
// 대회 or 인턴
// Written in C++ langs
// 2020. 03. 05.
// Wizley

#include <algorithm>
#include <iostream>

using namespace std;

int N, M, K;
int RES;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K;
    
    if(N > M*2){
        RES = M;
        K = K - (N - M*2);
    }
    
    else{
        RES = N/2;
        K = K - (M - N/2);
        
    }
    
    if(K>0){
        if (K<3) RES = RES - 1;
        else{
            RES = RES - (K/3);
            if(K%3) RES = RES - 1;
        }
    }
    
    cout << RES << "\n";
    
    return 0;
    
}

