// https://www.acmicpc.net/problem/11062
// 카드 게임
// Written in C++ langs
// 2020. 06. 15.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;
int DP[1001][1001];

int solve(vector<int> &card, int L, int R){
    
    // OOB 조심 !
    if(L > R || R<0) return 0;
    
    // 초기값이 아닌 최신화 된 값을 가지고 있을 경우
    if(DP[L][R] != -1){
        return DP[L][R];
    }
    
    // 재귀의 첫 시작
    if(L == R){
        return DP[L][R] = card[L];
    }
    
    // front를 선택할 경우
    DP[L][R] = card[L] + min(solve(card,L+1,R-1), solve(card,L+2,R));
    
    // back을 선택할 경우
    DP[L][R] = max(DP[L][R], card[R] + min(solve(card,L+1,R-1), solve(card,L,R-2)));
    
    return DP[L][R];
}

int main(){
    ios_base :: sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    for(int t=0; t<T; t++){
        cin >> N;
        
        vector<int> card;
        
        for(int i=0; i<1001; i++){
            for(int j=0; j<1001; j++){
                DP[i][j] = -1;
            }
        }
        
        int no;
        for(int n=0; n<N; n++){
            cin >> no;
            card.push_back(no);
        }

        cout << solve(card, 0, N-1) << "\n";
        
    }
    
    
    return 0;
    
}

