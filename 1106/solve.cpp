// https://www.acmicpc.net/problem/1106
// 호텔
// Written in C++ langs
// 2020. 08. 19.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321

using namespace std;

int N, C;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> C >> N;
    
    vector<pair<int,int>> info;
    vector<int> dp(2001, INF);
    
    dp[0] = 0;
    
    int cost, customer;
    for(int i=0; i<N; i++){
        cin >> cost >> customer;
        info.push_back(make_pair(cost, customer));
        dp[customer] = min(dp[customer], cost);
        
    }
    
    for(int i=1; i<2001; i++){
        if(dp[i] == INF) continue;
        
        for(int j=1; j<2001; j++){
            if(dp[j] == INF) continue;

            if(i+j > 2000) break;
            dp[i+j] = min(dp[i+j], dp[i]+dp[j]);
        }
        
    }
    
    int result = INF;
    for(int i=C; i<2001; i++){
        result = min(result, dp[i]);
    }
    
    cout << result << "\n";

    return 0;
}

