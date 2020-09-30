// https://www.acmicpc.net/problem/13398
// 연속합 2
// Written in C++ langs
// 2020. 09. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    vector<int> arr(N);
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    // 해당 자릿수부터 마지막 자릿수까지 더해서 얻을 수 있는 가장 큰 값
    int dp[100001][2] = {0,};
    
    dp[0][0] = arr[0];
    dp[0][1] = arr[0];
    
    int res = arr[0];
    for(int i=1; i<N; i++){
        // 특정 자리의 숫자를 포함하지 않은 경우
        // 이번 자리에서 포함하지 않거나, 그 전에 이미 포함되지 않은 경우만 존재
        dp[i][0] = max(dp[i-1][1], dp[i-1][0]+arr[i]);
        // 모든 숫자를 사용한 경우
        // 해당 숫자로부터 시작을 하거나 해당 숫자까지의 합을 가짐
        dp[i][1] = max(arr[i], dp[i-1][1]+arr[i]);
        
        res = max(res, dp[i][0]);
        res = max(res, dp[i][1]);
    }

    cout << res << "\n";
    
    return 0;
    
}

