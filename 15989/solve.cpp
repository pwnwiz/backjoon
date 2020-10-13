// https://www.acmicpc.net/problem/15989
// 1, 2, 3 더하기 4
// Written in C++ langs
// 2020. 10. 32.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N;
int DP[10001][4];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    // DP[number][last_used]
    // should be ascend order
    DP[1][1] = 1;
    DP[2][1] = 1;
    DP[2][2] = 1;
    DP[3][1] = 1;
    DP[3][2] = 1;
    DP[3][3] = 1;
    
    for(int i=4; i<=10000; i++){
        DP[i][1] = DP[i-1][1];
        DP[i][2] = DP[i-2][1] + DP[i-2][2];
        DP[i][3] = DP[i-3][1] + DP[i-3][2] + DP[i-3][3];
    }
    
    int c;
    for(int i=0; i<N; i++){
        cin >> c;
        
        int sum = 0;
        for(int i=1; i<=3; i++){
            sum += DP[c][i];
        }
        cout << sum << "\n";
    }
    
    return 0;
    
}

