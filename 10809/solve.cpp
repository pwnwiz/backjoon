// https://www.acmicpc.net/problem/10809
// 알파벳 찾기
// Written in C++ langs
// 2020. 01. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int ARR[27]={0,};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string S;
    cin >> S;
    
    for(int i=0; i<26; i++)
        ARR[i] = -1;
    
    for(int i=0; i<S.size(); i++){
        if(ARR[S[i]-'a'] == -1) ARR[S[i]-'a'] = i;
    }
    
    for(int i=0; i<26; i++)
        cout << ARR[i] << " ";
        
    cout << "\n";
    
    return 0;
}

