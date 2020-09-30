// https://www.acmicpc.net/problem/14002
// 가장 긴 증가하는 부분 수열 4
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
    int dp[1001] = {0,};
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    dp[0] = 1;
    int cnt = 1;
    
    for(int i=1; i<N; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
                cnt = max(cnt, dp[i]);
            }
        }
    }
    
    cout << cnt << "\n";
    
    vector<int> res;
    
    for(int i=N-1; i>=0; i--){
        if(dp[i] == cnt){
            if(res.empty()){
                res.push_back(arr[i]);
                cnt--;
            }
            else{
                if(arr[i]>res.back()) continue;
                res.push_back(arr[i]);
                cnt--;
            }
        }
    }
    
    reverse(res.begin(), res.end());
    
    for(auto r : res){
        cout << r << " ";
    }
    cout << "\n";
    
    return 0;
    
}

