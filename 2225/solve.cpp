// https://www.acmicpc.net/problem/2225
// 합분해
// Written in C++ langs
// 2020. 01. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long DP[201][201]={0,};

int main() {
    int N, K;

    cin >> N;
    cin >> K;

    for(int i=0; i<=N; i++){
        DP[i][1] = 1;
    }

    for(int k=2; k<=K; k++){
        for(int n=0; n<=N; n++){
            for(int p=0; p<=n; p++){
                DP[n][k] += DP[p][k-1];
            }
            DP[n][k] %= 1000000000;
        }
    }
    cout << DP[N][K] << endl;
    return 0;
}

