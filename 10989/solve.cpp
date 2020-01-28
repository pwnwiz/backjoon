// https://www.acmicpc.net/problem/10989
// 수 정렬하기 3
// Written in C++ langs
// 2020. 01. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

int ARR[10001]={0,};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int count, no;
    cin >> count;
    
    for(int i=0; i<count; i++){
        cin >> no;
        ARR[no]++;
    }
    
    for(int i=1; i<10001; i++){
        for(int j=0; j<ARR[i]; j++){
            cout << i << "\n";
        }
    }
    
    return 0;
}

