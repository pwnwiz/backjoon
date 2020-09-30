// https://www.acmicpc.net/problem/15990
// 1, 2, 3 더하기 5
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
    
    // dp[시작하는 번호][끝나는 번호]
    long long dp[100001][4] = {0,};
    
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    
    // 결국 해당 자릿수에서 마지막으로 사용된 값과 i-1에서 마지막에 사용된 값이 같지 않으면 됨
    for(int i=4; i<=100000; i++){
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % 1000000009;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % 1000000009;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % 1000000009;
    }
    
    int n;
    for(int t=0; t<T; t++){
        cin >> n;
        cout << (dp[n][1]+dp[n][2]+dp[n][3]) % 1000000009 << "\n";
    }


    return 0;
    
}

