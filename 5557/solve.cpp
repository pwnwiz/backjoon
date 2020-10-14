// https://www.acmicpc.net/problem/5557
// 1학년
// Written in C++ langs
// 2020. 10. 14.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

long long DP[101][2][21];
int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    vector<int> v(N);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    
    memset(DP, -1, sizeof(DP));
    
    DP[0][0][v[0]] = 1;
    for(int i=1; i<N-1; i++){
        for(int exp=0; exp<2; exp++){
            for(int k=0; k<=20; k++){
                if(DP[i-1][exp][k] != -1){
                    if(k+v[i]<=20 && k+v[i]>=0){
                        if(DP[i][0][k+v[i]] == -1) DP[i][0][k+v[i]] = 0;
                        DP[i][0][k+v[i]] += DP[i-1][exp][k];
                    }
                    if(k-v[i]>=0 && k-v[i]<=20){
                        if(DP[i][1][k-v[i]] == -1) DP[i][1][k-v[i]] = 0;
                        DP[i][1][k-v[i]] += DP[i-1][exp][k];
                    }
                }
            }
        }
    }

    if(DP[N-2][0][v[N-1]] == -1) DP[N-2][0][v[N-1]] = 0;
    if(DP[N-2][1][v[N-1]] == -1) DP[N-2][1][v[N-1]] = 0;
    cout << DP[N-2][0][v[N-1]] + DP[N-2][1][v[N-1]] << "\n";
    
}

