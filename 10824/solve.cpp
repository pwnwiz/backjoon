// https://www.acmicpc.net/problem/10824
// 네 수
// Written in C++ langs
// 2020. 01. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    
    string a = to_string(A) + to_string(B);
    string b = to_string(C) + to_string(D);
    
    long long result = stoll(a) + stoll(b);
    cout << result << "\n";
    
    return 0;
}



