// https://www.acmicpc.net/problem/2169
// 로봇 조종하기
// Written in C++ langs
// 2020. 06. 11.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int MAP[1000][1000];
int DP[1000][1000];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
        }
    }
    
    DP[0][0] = MAP[0][0];
    for(int i=1; i<M; i++){
        DP[0][i] = DP[0][i-1] + MAP[0][i];
    }

    // tmp[0] => 왼쪽에서 오른쪽으로 최댓값
    // tmp[1] => 오른쪽에서 왼쪽으로 최댓값
    int tmp[2][1000];
    for(int i=1; i<N; i++){
        // 맨 왼쪽 값은 위로부터 내려오는 경우밖에 존재하지 않음
        tmp[0][0] = DP[i-1][0]+MAP[i][0];

        // 왼쪽에서 오른쪽으로 가는 경우
        for(int j=1; j<M; j++){
            tmp[0][j] = max(tmp[0][j-1]+MAP[i][j], DP[i-1][j]+MAP[i][j]);
        }

        // 맨 오른쪽 값은 위로부터 내려오는 경우밖에 존재하지 않음
        tmp[1][M-1] = DP[i-1][M-1]+MAP[i][M-1];
        
        // 오른쪽에서 왼쪽으로 가는 경우
        for(int j=M-2; j>=0; j--){
            tmp[1][j] = max(tmp[1][j+1]+MAP[i][j], DP[i-1][j]+MAP[i][j]);
        }
        
        for(int j=0; j<M; j++){
            DP[i][j] = max(tmp[0][j], tmp[1][j]);
        }
    }

    cout << DP[N-1][M-1] << "\n";
    
    return 0;
    
}

