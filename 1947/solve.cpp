// https://www.acmicpc.net/problem/1947
// 선물 전달
// Written in C++ langs
// 2020. 09. 02.
// Wizley

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long DP[1000001];
int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    DP[0] = 0;
    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 2;
    
    for(int i=4; i<=N; i++){
        DP[i] = (i-1)*(DP[i-1]+DP[i-2]) % 1000000000;
    }
    
    cout << DP[N] << "\n";
    
    return 0;
    
}

