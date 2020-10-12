// https://www.acmicpc.net/problem/10942
// 팰린드롬?
// Written in C++ langs
// 2020. 10. 12.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
bool DP[2001][2001];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    vector<int> v(N);
    
    for(int i=0; i<N; i++){
        cin >> v[i];
        DP[i][i] = true;
    }
    
    for(int len=2; len<=N; len++){
        for(int s=0; s<=N-len; s++){
            int e = s+len-1;
            
            if(len == 2){
                if(v[s] == v[s+1]) DP[s][e] = true;
            } else {
                if(DP[s+1][e-1] && v[s] == v[e]) DP[s][e] = true;
            }
        }
    }

    cin >> M;
    
    int f, t;
    for(int i=0; i<M; i++){
        cin >> f >> t;
        cout << DP[f-1][t-1] << "\n";
    }
    
    return 0;
    
}

