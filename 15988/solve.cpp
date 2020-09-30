// https://www.acmicpc.net/problem/15988
// 1, 2, 3 더하기 3
// Written in C++ langs
// 2020. 09. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    long long dp[1000001] = {0,};
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int i=4; i<=1000000; i++){
        for(int j=1; j<=3; j++){
            dp[i] = (dp[i] + dp[i-j]) % 1000000009;
        }
    }
    
    int n;
    for(int t=0; t<T; t++){
        cin >> n;
        cout << dp[n] << "\n";
    }
    
    
    return 0;
    
}

