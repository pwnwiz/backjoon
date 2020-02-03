// https://www.acmicpc.net/problem/1182
// 부분수열의 합
// Written in C++ langs
// 2020. 02. 03.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int ARR[1000001]={0,};
int SIZE;
int VAL;
int RESULT=0;

void findCase(int idx, int sum){
    if(idx == SIZE){
        if(sum == VAL) RESULT++;
        return;
    }
    
    findCase(idx+1,sum+ARR[idx]);
    findCase(idx+1,sum);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> SIZE >> VAL;
    
    for(int i=0; i<SIZE; i++){
        cin >> ARR[i];
    }
    
    findCase(0, 0);
    if(VAL == 0) RESULT = RESULT - 1;
    cout << RESULT << "\n";
}

