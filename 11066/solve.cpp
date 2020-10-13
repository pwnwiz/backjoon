// https://www.acmicpc.net/problem/11066
// 파일 합치기
// Written in C++ langs
// 2020. 10. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

int T, N;
int DP[501][501];

int findSum(vector<int> &v, int s, int e){
    if(s == e){
        return v[s];
    }
    
    if(DP[s][e] != -1) return DP[s][e];
    
    int sum = accumulate(v.begin()+s, v.begin()+e+1, 0);
    
    DP[s][e] = 987654321;
    for(int m=s; m<e; m++){
        DP[s][e] = min(DP[s][e], findSum(v, s, m)+findSum(v, m+1, e)+sum);
    }

    return DP[s][e];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    cin >> T;
    
    for(int t=0; t<T; t++){
        memset(DP, -1, sizeof(DP));
        
        cin >> N;
        
        vector<int> v(N);
        
        for(int i=0; i<N; i++){
            cin >> v[i];
        }
        
        int result = 987654321;
        
        for(int m=0; m<N-1; m++){
            result = min(result, findSum(v, 0, m)+findSum(v, m+1, N-1));
        }
        
        cout << result << "\n";
    }
    
    
}

