// https://www.acmicpc.net/problem/7579
// 앱
// Written in C++ langs
// 2020. 06. 12.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> APP;
int DP[101*100];
int N, M;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    int mem;
    for(int i=0; i<N; i++){
        cin >> mem;
        APP.push_back(make_pair(mem,0));
    }
    
    int total = 0;
    int cost;
    for(int j=0; j<N; j++){
        cin >> cost;
        APP[j].second = cost;
        total += cost;
    }
    
    fill(DP, DP+101*100, 0);
    
    // 범위가 천만이기 때문에 메모이제이션을 하기 위한 기준으로 cost를 사용함
    for(int i=0; i<N; i++){
        for(int j=total; j>=APP[i].second; j--){
            DP[j] = max(DP[j], DP[j-APP[i].second]+APP[i].first);
        }
    }
    
    for(int i=0; i<total; i++){
        if(DP[i] >= M){
            cout << i << "\n";
            break;
        }
    }
    
    return 0;
    
}

