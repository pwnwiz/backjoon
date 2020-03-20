// https://www.acmicpc.net/problem/1759
// 암호 만들기
// Written in C++ langs
// 2020. 03. 20.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int L, C;
char ARR[16]={0,};
char VOWELS[5] = {'a', 'i', 'o', 'u', 'e'};

void backtracking(string password, int idx, int vowelcount, int consonantcount){
    
    if(password.length() == L){
        if(vowelcount>=1 && consonantcount>=2){
            cout << password << "\n";
        }
        return;
    }
    
    for(int i=idx+1; i<C; i++){
        if(find(VOWELS, VOWELS+5, ARR[i]) != VOWELS+5){
            backtracking(password + ARR[i], i, vowelcount+1, consonantcount);
        }
        else{
            backtracking(password + ARR[i], i, vowelcount, consonantcount+1);
        }
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> L >> C;
    for(int i=0; i<C; i++){
        cin >> ARR[i];
    }
    
    sort(ARR, ARR+C);
    backtracking("", -1, 0, 0);

    return 0;
    
}

