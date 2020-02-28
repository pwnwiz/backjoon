// https://www.acmicpc.net/problem/11728
// 배열 합치기
// Written in C++ langs
// 2020. 02. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int ARR[2000001]={0,};
int N, M;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    for(int i=0; i<N+M; i++){
        cin >> ARR[i];
    }
    
    sort(ARR, ARR+N+M);
    for(int i=0; i<N+M; i++){
        cout << ARR[i] << " ";
    }
    cout << "\n";
    
    return 0;
    
}

