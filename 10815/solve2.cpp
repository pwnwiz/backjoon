// https://www.acmicpc.net/problem/10815
// 숫자 카드
// Written in C++ langs
// 2020. 02. 27.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

bool ARR[20000002]={0,};
bool RES[500001]={0,};
int K;
int INPUT;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    for(int i=0; i<K; i++){
        cin >> INPUT;
        ARR[10000000+INPUT]=1;
    }
    
    int count;
    int val;
    cin >> count;
    for(int i=0; i<count; i++){
        cin >> val;
        RES[i] = ARR[10000000+(val)];
    }

    for(int i=0; i<count; i++){
        cout << RES[i] << " ";
    }
    cout << "\n";
    
    return 0;
    
}

