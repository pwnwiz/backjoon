// https://www.acmicpc.net/problem/11659
// 구간 합 구하기 4
// Written in C++ langs
// 2020. 11. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

using namespace std;

vector<int> V;
int N, M;
int SUM[100001];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    cin >> N >> M;
    V.resize(N);
    
    SUM[0] = 0;
    for(int i=0; i<N; i++){
        cin >> V[i];
        SUM[i+1] = V[i] + SUM[i];
    }
    
    int f, t;
    for(int i=0; i<M; i++){
        cin >> f >> t;
        cout << SUM[t] - SUM[f-1] << "\n";
    }
    
   
    
    return 0;
}

