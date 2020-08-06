// https://www.acmicpc.net/problem/1727
// 커플 만들기
// Written in C++ langs
// 2020. 08. 06.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int N, M;
int DP[1001][1001];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> men;
    vector<int> women;
    
    cin >> N >> M;
    
    int in;
    for(int i=0; i<N; i++){
        cin >> in;
        men.push_back(in);
    }
    
    for(int j=0; j<M; j++){
        cin >> in;
        women.push_back(in);
    }
    
    sort(men.begin(), men.end());
    sort(women.begin(), women.end());
    
    // DP[남자][여자]
    DP[0][0] = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            // 남자 == 여자 ( 짝을 지을 수 있는 상태 )
            DP[i][j] = DP[i-1][j-1] + abs(men[i-1]-women[j-1]);
            
            // 짝을 지은 것과 짓지 않은 그 전 상태를 비교
            // 남자 > 여자
            if(i>j){
                DP[i][j] = min(DP[i-1][j], DP[i][j]);
            }
            // 여자 > 남자
            if(j>i){
                DP[i][j] = min(DP[i][j-1], DP[i][j]);
            }
        }
    }
    
    cout << DP[N][M] << "\n";

    
    return 0;
    
}

