// https://www.acmicpc.net/problem/11058
// 크리보드
// Written in C++ langs
// 2020. 10. 32.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

long long DP[101];
int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 3;
    
    for(int i=4; i<=N; i++){
        // Option 1
        DP[i] = DP[i-1] + 1;
        
        // Option 2->3->4
        DP[i] = max(DP[i], DP[i-3]*2);

        // Option 2->3->4->4->...->4
        for(int j=4; j<=i; j++){
            DP[i] = max(DP[i], DP[i-j]*(j-1));
        }
    }
    
    cout << DP[N] << "\n";
}

