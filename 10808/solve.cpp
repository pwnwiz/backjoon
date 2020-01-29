// https://www.acmicpc.net/problem/10808
// 알파벳 개수
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
    
    for(int i=0; i<S.size(); i++)
        ARR[S[i]-'a'] ++;
    
    for(int i=0; i<26; i++)
        cout << ARR[i] << " ";
        
    cout << "\n";
    return 0;
}



