// https://www.acmicpc.net/problem/7453
// 합이 0인 네 정수
// Written in C++ langs
// 2020. 03. 25.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N;
long long COUNT = 0;

int A[4001]={0,};
int B[4001]={0,};
int C[4001]={0,};
int D[4001]={0,};
int AnB[4000*4000]={0,};
int CnD[4000*4000]={0,};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    int idx=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            AnB[idx] = A[i] + B[j];
            CnD[idx] = C[i] + D[j];
            idx++;
        }
    }
    
    sort(CnD, CnD+idx);
        
    for(int i=0; i<idx; i++){
        auto range = equal_range(CnD, CnD+idx, -AnB[i]);
        COUNT += range.second - range.first;
    }

    cout << COUNT << "\n";
    
    return 0;
    
}

