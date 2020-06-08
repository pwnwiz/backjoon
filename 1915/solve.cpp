// https://www.acmicpc.net/problem/1915
// 가장 큰 정사각형
// Written in C++ langs
// 2020. 06. 08.
// Wizley

#include <algorithm>
#include <iostream>

using namespace std;

int N, M;

int ARR[1000][1000];
int DP[1000][1000];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    int max_elem = 0;
    
    char in;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> in;
            DP[i][j] = ARR[i][j] = in - '0';
            if(ARR[i][j] == 1) max_elem = 1;
        }
    }
    
    for(int i=1; i<N; i++){
        for(int j=1; j<M; j++){
            if(DP[i][j] == 1){
                DP[i][j] = min(DP[i-1][j-1], min(DP[i-1][j], DP[i][j-1]))+1;
                max_elem = max(max_elem, DP[i][j]);
            }
        }
    }
    
    cout << max_elem * max_elem << "\n";
    
    return 0;
    
}

