// https://www.acmicpc.net/problem/1377
// 버블 소트
// Written in C++ langs
// 2020. 03. 27.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

typedef struct BURBLE{
    int val;
    int idx;
}BURBLE;

int N;
BURBLE ARR[500001];
int COUNT=0;

bool compare(const BURBLE &A, const BURBLE &B){
    return A.val < B.val;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> ARR[i].val;
        ARR[i].idx = i;
    }
    
    stable_sort(ARR, ARR+N, compare);
    
    for(int i=0; i<N; i++){
        COUNT = max(ARR[i].idx-i+1, COUNT);
    }
    
    cout << COUNT << "\n";
    
    return 0;
    
}

